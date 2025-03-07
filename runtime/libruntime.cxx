#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

#include "export.hxx"
#include "../comp/compat"
#include "../reg/register.hxx"
#include "../parser/parserEssentials.hxx"
#include "../inst/inst.hxx"

namespace runtime {

  std::uint8_t panic(std::string msg) {
    std::cerr << "\033[0;31mProcess Panicked: " << msg << "\033[0m" << std::endl;
    #ifdef linux
      #ifdef __x86_64__
        __asm__(".intel_syntax noprefix");
        __asm__("mov rax, 60");
        __asm__("xor rdi, rdi");
        __asm__("add rdi, 1");
        __asm__("syscall");
        __asm__(".att_syntax");
      
      #else
        exit(1);
      #endif
    #else
      exit(1);
    #endif
    
    return 1;
  }

  void_t exitA(std::uint8_t code) {

    for (int i = 0; i < REG_SIZE; ++i) {
      reg::RegX[i].deinit();
    }

    exit(code);
  }

  std::uint8_t initRegisters() {

    for (std::uint16_t i = 0; i < REG_SIZE; ++i) {
      std::uint8_t result = reg::RegX[i].init();
      if (result == 1) 
        return 1;
    }
    reg::sstack.push_back(reg::RegX[0]);
    return 0;

  }

  bool executor(parser::basicParse_t& tokens) {
    
    if (tokens.instruction == parser::statreg) {
      instruction::statreg(tokens.regIndex[0]);

    } else if (tokens.instruction == parser::statstack) {
      instruction::statstack(tokens.regIndex[0]);

    } else if (tokens.instruction == parser::hlt) {
      instruction::halt();

    } else if (tokens.instruction == parser::mov)  {
      instruction::mov(tokens.regIndex[0], tokens.regIndex[1], tokens.config1, tokens.integer1, tokens.str1, tokens.StrConfig);

      if (tokens.StrConfig) free(tokens.str1);
      
    }
    
    else {
      panic("Invalid Instruction");
    }

    return true;
  }

}  
