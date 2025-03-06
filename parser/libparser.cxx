
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "parserEssentials.hxx"
#include "../runtime/export.hxx"
#include "../comp/compat"
#include "../virt/export.hxx"
#include "parserStructure.hxx"

void TwoRegisterCheck(std::vector<std::string>& tokens, parser::basicParse_t& RetVal) {
    if (tokens.size() != 3) runtime::panic("Invalid Number Of Tokens");
    if (tokens[1].size() < 2) runtime::panic("Invalid Register Size");
    if (tokens[1][0] != 'x') runtime::panic("Invalid Register Name");
    if (tokens[2][0] != 'x' && virtualSpace::is_digit(tokens[2][0])) RetVal.config1 = true; //reg number
    else if (tokens[2][0] == 'x') RetVal.config1 = false; //reg reg
    else runtime::panic("Invalid Register Name");
    
    std::string RegStr = tokens[1];
    RegStr.erase(0, 1);
    std::uint16_t RegIndex = std::stoi(RegStr);
    if (RegIndex > REG_SIZE) runtime::panic("Invalid Register Index");
    RetVal.regIndex[0] = RegIndex;
    if (RetVal.config1) {

    } else if (!RetVal.config1) {
        std::string RegStr = tokens[2];
        RegStr.erase(0, 1);
        std::uint16_t RegIndex = std::stoi(RegStr);
        RetVal.regIndex[1] = RegIndex;
        if (RegIndex > REG_SIZE) runtime::panic("Invalid Register Index");
    }
}


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
        } else if (tokens[0] == "mov") {
            TwoRegisterCheck(tokens, RetVal);
            
            RetVal.instruction = mov;
            
        }

        else {
            runtime::panic("Invalid Instruction");
        }


        return RetVal;
    }

}  // namespace parser