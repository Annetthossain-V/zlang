#include <cstdint>
#include <string>

namespace runtime {
  typedef void void_t;
  typedef double double_t;
  typedef int int_t;
  typedef char char_t;
  typedef long long_t;
  
  

  
  std::uint8_t panic(std::string msg);
  runtime::void_t exitA(std::uint8_t code);
}