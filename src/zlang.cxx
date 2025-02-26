#ifdef lite 
  #undef linux
#endif


#include <cstdint>
#include <cstdlib>
#include <iostream>
#include "../runtime/export.hxx"
#include <print>

#ifdef linux
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include <string>
#include <sys/types.h>
#include <fstream>

std::uint8_t cli();
std::uint8_t fileReader(std::string name, std::string function);
void lineProcessor(std::string& line);

int main(int argc, char** argv) {
  std::string Version = "Version: 0.1rc6, ";
  #ifdef linux 
    Version.append("linux");
  #endif
  #ifdef lite
    Version.append("Lite");
  #endif

  std::uint8_t status = 1;
  if (argc < 2)
    status = cli();
  else if (argc == 2 && (std::string)argv[1] == "--version")
  {  std::cout << Version << std::endl; runtime::exitA(0); }
  else if (argc == 2)
    status = fileReader(argv[1], "");


  runtime::exitA(status);
  while (true) {} // halt

}


std::uint8_t cli() {
  char* input = nullptr;

  #ifdef linux

    rl_initialize();
    using_history();

    while (true) {
      input = readline("zlang> ");
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

std::uint8_t fileReader(std::string name, std::string function) {
  if (function == "")
    function = "main:";


  std::ifstream file(name);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << name << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line == "") continue;
    lineProcessor(line);
  }

  file.close();
  return 0;
}


void lineProcessor(std::string& line) {
  std::cout << line << std::endl;
  return;
}