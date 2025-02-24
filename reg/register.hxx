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
  r_128,
  r_string,
  r_nill,
  
} rmode_t;

typedef struct {
  bool if_equal;
  bool if_zero;
  bool if_not_equal;
  bool if_not_zero;
  bool if_greater;
  bool if_not_less_or_equal;
  bool if_greater_or_equal;
  bool if_not_less;
  bool if_less;
  bool if_not_greater_or_equal;
  bool if_less_or_equal;
  bool if_not_greater;
} statusFlag_t;

typedef union {
  std::int16_t bit16; // 16 bit mode (low mode)
  std::int32_t bit32; // 32 bit mode (default)
  std::double_t bit64; // 64 bit mode (float)
} rdata_t;

typedef struct {
   rmode_t mode; // register mode
   rdata_t data; // data section
   std::string sstring; // registers string data section
   void* ptr; // register's pointer section
   std::uint16_t strlen; // sstring's length
   statusFlag_t statFlags; // status flags
   bool interrupt; // interrupts allow status
     
} reg_t;



class Register {
public:
  std::uint8_t init(reg::rmode_t mode);
  std::uint8_t deinit(reg::rmode_t mode);
  std::uint8_t editDataSection();
  std::uint8_t editStringSection();
  std::uint8_t editPtrSection();
  std::uint8_t editSFlagSection();
  std::uint8_t editEtcSection(bool *interrupt, rmode_t* mode);
  std::uint8_t reset();

private:
  reg_t data;
  std::uint16_t useCycle;
};






extern Register RegX[REG_SIZE];

extern std::vector<Register> sstack;

} // namespace reg
