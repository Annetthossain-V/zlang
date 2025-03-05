#include <thread>
#include <string>
#include "../reg/register.hxx"

namespace virtualSpace {
    bool strcmp(std::string str1, std::string str2) {
        if (str1 == str2)
            return true;
        else
          return false;
    }
    #ifdef linux
    void libloader(std::string name) {
        
    }
    #endif
    bool is_digit(char s) {
        if (s >= '0' && s <= '9')
            return true;
        else
            return false;
    }

}
