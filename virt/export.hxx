#pragma once
#include <string>

namespace virtualSpace {
    bool strcmp(std::string str1, std::string str2);
    #ifdef linux
    void libloader(std::string name);
    #endif
    
}
