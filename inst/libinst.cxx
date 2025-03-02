#include <cstdint>

namespace instruction {
    void statreg(std::uint16_t Rindex) {
        while (true) {
            __asm__("nop");
        }
    }
}