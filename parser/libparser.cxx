#include <vector>
#include <string>
#include <sstream>
#include "parserStructure.hxx"


namespace parser {

    std::vector<std::string> StringSplitter(std::string str) {
        std::vector<std::string> result;
        std::stringstream iss(str);
        std::string token;
        while (iss >> token) {
            result.push_back(token);
        }

        return result;
    }

    basicParse_t tokenizeBasic(std::vector<std::string> tokens);

}  // namespace parser