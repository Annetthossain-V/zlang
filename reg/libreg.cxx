#include "register.hxx"
#include "../comp/compat"
#include <cstdint>
#include <vector>

namespace reg {

Register RegX[REG_SIZE] = {};

std::vector<Register> sstack;


}


namespace reg {
    // impl for reggister class
    std::uint8_t Register::editDataSection(std::uint8_t data16, std::uint32_t data32, double data64) {
        switch (this->currentMode) {
            case r_16:
                this->data.bit16 = data16;
                break;
            case r_32:
                this->data.bit32 = data32;
                break;
            case r_64:
                this->data.bit64 = data64;
                break;
            default:
                return 1;
        }
        return 0;
    }


}