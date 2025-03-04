#pragma once
#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include "../comp/compat"

namespace reg {

typedef enum {
  r_16,
  r_32,
  r_64,
  r_string,
  r_pointer,
  r_nill,
  
} rmode_t;


typedef union {
  std::int16_t bit16; // 16 bit mode (low mode)
  std::int32_t bit32; // 32 bit mode (default)
  std::double_t bit64; // 64 bit mode (float)
  void* ptr; // pointer mode
} rdata_t;


class Register {
public:
  std::uint8_t init();
  std::uint8_t deinit();
  std::uint8_t editDataSection(std::int8_t data16, std::int32_t data32, double data64);
  std::uint8_t editStringSection(std::string data);
  std::uint8_t editPtrSection(void* ptr);
  std::uint8_t editCurrentMode(rmode_t mode);

  // getting the data
  rdata_t getData();
  std::string getString();
  std::uint16_t getStrlen();
  rmode_t getCurrentMode();

private:
  rdata_t data; 
  std::string sstring;
  std::uint16_t strlen;
  std::uint32_t useCycle;
  rmode_t currentMode;
};






extern Register RegX[REG_SIZE];

extern std::vector<Register> sstack;

} // namespace reg
