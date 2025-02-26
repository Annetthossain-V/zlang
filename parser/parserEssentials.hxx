#pragma once

#include <vector>
#include <string>
#include "parserStructure.hxx"

namespace parser {

    std::vector<std::string> StringSplitter(std::string& str);
    basicParse_t tokenizeBasic(std::vector<std::string>& tokens);
}