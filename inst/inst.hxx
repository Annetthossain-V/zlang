#pragma once
#include <cstdint>
#include <string>

namespace instruction {
    void statreg(std::uint16_t Rindex);
    void statstack(std::uint16_t sIndex);
    void halt();
    void mov(std::uint16_t Register1, std::uint16_t Register2, bool dualRegister, double IntegerContent, char* StringContent, bool RegisterString);
}