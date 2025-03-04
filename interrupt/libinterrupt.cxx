#include <string>

namespace interrupt {

void interruptHandler(std::string codename) {
    __asm__(".intel_syntax noprefix");
    __asm__("cli");
    __asm__("hlt");
    __asm__(".att_syntax");
}


}