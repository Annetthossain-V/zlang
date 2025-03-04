// #include "../comp/compat"

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include "../runtime/export.hxx"
#include <print>
#include <vector>

#ifdef linux
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include <string>
#include <sys/types.h>
#include <fstream>

#include "../parser/parserEssentials.hxx"
#include "../comp/config.hxx"

bool jmp = false;
std::string function = "main:";

std::uint8_t cli();
std::uint8_t fileReader(std::string name, std::string& function);
void lineProcessor(std::string& line);

// The Limit Is Only Your Imagination

// convention args=(x2 - x14) ret=(x1)
int main(int argc, char** argv) {
  std::string Version = "Version: 0.2.rc1, Code Name: Nova, Target: ";
  #ifdef linux 
    Version.append("linux");
  #endif
  #ifdef lite
    Version.append("Lite");
  #endif

  runtime::initRegisters();
  config::Conf.init();


  std::uint8_t status = 1;
  if (argc < 2)
    status = cli();
  else if (argc == 2 && (std::string)argv[1] == "--version")
  {  std::cout << Version << std::endl; runtime::exitA(0); }
  else if (argc == 2) {
    status = fileReader(argv[1], function); 
    while (jmp == true) { 
      jmp = false; 
      status = fileReader(argv[1], function); 
    } 
  }

  
  runtime::exitA(status);
  while (true) {} // halt

}


std::uint8_t cli() {
  char* input = nullptr;

  #ifdef linux

    rl_initialize();
    using_history();

    while (true) {
      input = readline("zlang$ ");
      if (input == nullptr) { continue; }
      add_history(input);
      std::string inputStr(input);

      if (inputStr == "") { free(input); continue; }
      if (inputStr == "exit()") { free(input); break; }

      lineProcessor(inputStr);

      free(input);
    }
  #else
    while (true) {
      input = (char*) malloc(2048);
      std::cout << "> ";
      std::fgets(input, 2048, stdin);
      
      std::string inputStr(input);
      if (inputStr == "") { free(input); continue; }
      if (inputStr == "exit()") { free(input); break; }

      lineProcessor(inputStr);

      free(input);
    }
  #endif

  return 0;
}

std::uint8_t fileReader(std::string name, std::string& function) {

  std::ifstream file(name);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << name << std::endl;
    return 1;
  }
  bool functionGotten = false;
  std::string line;
  while (std::getline(file, line)) {
    if (line == "") continue;
    
    if (functionGotten == false) {
      if (line == function) {
        functionGotten = true;

      }
      continue;
    }

    if (functionGotten == true && line.find(":") != std::string::npos) {
      return 0;
    }

    
    lineProcessor(line);

    if (jmp == true) {
      file.close();
      return 0;
    }
    
  }

  file.close();
  return 0;
}


void lineProcessor(std::string& line) {
  std::vector<std::string> lineSplit = parser::StringSplitter(line);
  parser::basicParse_t tokens = parser::tokenizeBasic(lineSplit);

  runtime::executor(tokens);


  return;
}
