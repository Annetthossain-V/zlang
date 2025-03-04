#include "register.hxx"
#include "../comp/compat"
#include <cstddef>
#include <cstdint>
#include <vector>

namespace reg {

Register RegX[REG_SIZE] = {};

std::vector<Register> sstack;


}


namespace reg {
    // impl for reggister class
    std::uint8_t Register::editDataSection(std::int8_t data16, std::int32_t data32, double data64) {
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
        this->useCycle++;
        return 0;
    }
    std::uint8_t Register::editStringSection(std::string data) {
        this->sstring = data;
        this->strlen = data.length();
        this->useCycle++;
        return 0;
    }
    
    std::uint8_t Register::editCurrentMode(rmode_t mode) {
        this->currentMode = mode;
        this->useCycle++;
        return 0;
    }
    std::uint8_t Register::init() {
        this->currentMode = r_16;
        this->data.bit16 = 0;
        this->sstring = "";
        this->strlen = 0;
        this->useCycle = 1;



        return 0;
    }
    std::uint8_t Register::deinit() {
        this->currentMode = r_16;
        this->data.bit16 = 0;
        this->sstring = "";
        this->strlen = 0;

        return 0;
    }

    rdata_t Register::getData() {
        this->useCycle++;
        return this->data;
    }
    std::string Register::getString() {
        this->useCycle++;
        return this->sstring;
    }
    std::uint16_t Register::getStrlen() {
        this->useCycle++;
        return this->strlen;
    }
    rmode_t Register::getCurrentMode() {
        this->useCycle++;
        return this->currentMode;
    }
}