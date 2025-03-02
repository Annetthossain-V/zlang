#pragma once

#include <string>
#include <vector>
#include "parserEnum.hxx"
#include <cstdint>

typedef struct {
    instruction_t instruction;
    std::uint8_t argcCount;
    std::uint16_t regIndex[3];
    
} basicParse_t;