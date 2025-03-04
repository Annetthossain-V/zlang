#include <cstdint>

namespace instruction {
    void statreg(std::uint16_t Rindex);
    void statstack(std::uint16_t sIndex);
    void halt();
    void mov();
}