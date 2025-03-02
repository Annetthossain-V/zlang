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

    exitA(1);
    #ifdef linux
      #ifdef __x86_64__
        __asm__(".intel_syntax noprefix");
        __asm__("mov rax, 60");
        __asm__("xor rdi, rdi");
        __asm__("add rdi, 2");
        __asm__("syscall");
        __asm__(".att_syntax");
      #endif
    #endif
    return 1;
  }

  void_t exitA(std::uint8_t code) {

    for (int i = 0; i < REG_SIZE; ++i) {
      reg::RegX[i].deinit();
    }

    exit(code);
    #ifdef linux
      #ifdef __x86_64__
        __asm__(".intel_syntax noprefix");
        __asm__("mov rax, 60");
        __asm__("xor rdi, rdi");
        __asm__("add rdi, 2");
        __asm__("syscall");
        __asm__(".att_syntax");
      #endif
    #endif
  }

  std::uint8_t initRegisters() {

    for (std::uint16_t i = 0; i < REG_SIZE; ++i) {
      std::uint8_t result = reg::RegX[i].init();
      if (result == 1) 
        return 1;
    }
    return 0;

  }

  bool executor(parser::basicParse_t& tokens) {
    
    if (tokens.instruction == parser::statreg) {
      instruction::statreg(tokens.regIndex[0]);
    }

    return true;
  }

}  
