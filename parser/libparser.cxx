
#include "../inc.H"

void TwoRegisterCheck(std::vector<std::string>& tokens, parser::basicParse_t& RetVal, bool& panic) {
    if (tokens.size() != 3) panic = true;
    if (tokens[1].size() < 2) panic = true;
    if (tokens[1][0] != 'x') panic = true;
    if (tokens[2][0] != 'x' && virtualSpace::is_digit(tokens[2][0])) RetVal.config1 = true; //reg number
    else if (tokens[2][0] == 'x') RetVal.config1 = false; //reg reg
    else panic = true;
    
    std::string RegStr = tokens[1];
    RegStr.erase(0, 1);
    std::uint16_t RegIndex = std::stoi(RegStr);
    if (RegIndex > REG_SIZE) panic = true;
    RetVal.regIndex[0] = RegIndex;
    if (RetVal.config1) {

    } else if (!RetVal.config1) {
        std::string RegStr = tokens[2];
        RegStr.erase(0, 1);
        std::uint16_t RegIndex = std::stoi(RegStr);
        RetVal.regIndex[1] = RegIndex;
        if (RegIndex > REG_SIZE) panic = true;
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
            bool panic = false;
            std::thread t1(TwoRegisterCheck, std::ref(tokens), std::ref(RetVal), std::ref(panic));
            RetVal.instruction = mov;
            t1.join();
            if (panic == true) { runtime::panic("Critical Parser Error: 404"); }
        }

        else {
            runtime::panic("Invalid Instruction");
        }


        return RetVal;
    }

}  // namespace parser
