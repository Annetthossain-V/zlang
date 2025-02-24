#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include "export.hxx"


namespace runtime {

  std::uint8_t panic(std::string msg) {
    std::cerr << "\033[0;31mProcess Panicked: " << msg << "\033[0m" << std::endl;
    std::exit(1);
    return 1;
  }

  runtime::void_t exitA(std::uint8_t code) {
    // deinit stuff
    exit(code);
  }  

}  
