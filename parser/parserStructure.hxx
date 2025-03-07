#pragma once

#include <string>
#include <vector>
#include "parserEnum.hxx"
#include <cstdint>

namespace parser {

    typedef struct {
        instruction_t instruction;
        std::uint8_t argcCount;
        std::uint16_t regIndex[3];
        bool config1;
        char* str1;
        double integer1;
        bool StrConfig;
    
    } basicParse_t;

}
