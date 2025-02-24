#pragma once

#include <string>
#include <vector>
#include "parserEnum.hxx"
#include <cstdint>

typedef struct {
    instruction_t instruction;
    std::uint8_t argCount;
    std::vector<std::string> arguments;
    
} basicParse_t;