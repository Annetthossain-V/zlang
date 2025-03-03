
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "parserEssentials.hxx"
#include "../runtime/export.hxx"
#include "../comp/compat"

namespace parser {

    std::vector<std::string> StringSplitter(std::string& str) {
        std::vector<std::string> result;
        std::stringstream iss(str);
        std::string token;
        while (iss >> token) {
            result.push_back(token);
        }

        return result;
    }

    basicParse_t tokenizeBasic(std::vector<std::string>& tokens) {
        basicParse_t RetVal;

        if (tokens[0] == "statreg") {
            if (tokens.size() != 2) runtime::panic("Invalid Number Of Tokens");
            std::string RName = tokens[1];
            if (RName.size() < 2) runtime::panic("Invalid Register Size");
            if (RName[0] != 'x') runtime::panic("Invalid Register Name");

            RName.erase(0, 1);
            std::uint16_t RIndex = std::stoi(RName);
            if (RIndex > REG_SIZE) runtime::panic("Invalid Register Index");

            RetVal.instruction = statreg;
            RetVal.argcCount = 1;
            RetVal.regIndex[0] = RIndex;
            
        } else if (tokens[0] == "statstack") {
            if (tokens.size() != 2) runtime::panic("Invalid Number Of Tokens");
            std::uint16_t sIndex = std::stoi(tokens[1]);
        

            RetVal.instruction = statstack;
            RetVal.argcCount = 1;
            RetVal.regIndex[0] = sIndex;

        } else if (tokens[0] == "hlt") {
            if (tokens.size() != 1) runtime::panic("Invalid Number Of Tokens");

            RetVal.instruction = hlt;
            RetVal.argcCount = 0;
        }

        else {
            runtime::panic("Invalid Instruction");
        }


        return RetVal;
    }

}  // namespace parser