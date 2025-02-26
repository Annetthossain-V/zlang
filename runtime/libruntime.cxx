#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

#include "export.hxx"
#include "../comp/compat"
#include "../reg/register.hxx"


namespace runtime {

  std::uint8_t panic(std::string msg) {
    std::cerr << "\033[0;31mProcess Panicked: " << msg << "\033[0m" << std::endl;
    std::exit(1);
    return 1;
  }

  void_t exitA(std::uint8_t code) {
    // deinit stuff
    exit(code);
  }

  std::uint8_t initRegisters() {

    for (std::uint16_t i = 0; i < REG_SIZE; ++i) {
      std::uint8_t result = reg::RegX[i].init();
      if (result == 1) 
        return 1;
    }
    return 0;

  }

}  
