#include <cstdint>
#include "../reg/register.hxx"
#include <iostream>
#include <cstdio>

namespace instruction {
    void statreg(std::uint16_t Rindex) {
        std::cout << "Register: " << "x" << Rindex << '\n';

        std::string currentMode;
        switch (reg::RegX[Rindex].getCurrentMode()) {
            case reg::r_16:
                currentMode = "16-bit";
                std::cout << "Data: " << reg::RegX[Rindex].getData().bit16 << '\n';
                break;
            case reg::r_32:
                currentMode = "32-bit";
                std::cout << "Data: " << reg::RegX[Rindex].getData().bit32 << '\n';
                break;
            case reg::r_64:
                currentMode = "64-bit";
                std::cout << "Data: " << reg::RegX[Rindex].getData().bit64 << '\n';
                break;
            case reg::r_string:
                currentMode = "String";
                std::cout << "Data: " << reg::RegX[Rindex].getString() << '\n';
                break;
            case reg::r_pointer:
                currentMode = "Pointer";
                std::cout << "Data: " << reg::RegX[Rindex].getData().ptr << '\n';
                break;
            case reg::r_nill:
                currentMode = "Nill";
                break;
        }
        std::cout << "Current Mode: " << currentMode << '\n';
        std::cout << "if_equal: " << reg::RegX[Rindex].getStatFlags().if_equal << '\n';
        std::cout << "if_zero: " << reg::RegX[Rindex].getStatFlags().if_zero << '\n';
        std::cout << "if_not_equal: " << reg::RegX[Rindex].getStatFlags().if_not_equal << '\n';
        std::cout << "if_not_zero: " << reg::RegX[Rindex].getStatFlags().if_not_zero << '\n';
        std::cout << "if_greater: " << reg::RegX[Rindex].getStatFlags().if_greater << '\n';
        std::cout << "if_not_less_or_equal: " << reg::RegX[Rindex].getStatFlags().if_not_less_or_equal << '\n';
        std::cout << "if_greater_or_equal: " << reg::RegX[Rindex].getStatFlags().if_greater_or_equal << '\n';
        std::cout << "if_not_less: " << reg::RegX[Rindex].getStatFlags().if_not_less << '\n';
        std::cout << "if_less: " << reg::RegX[Rindex].getStatFlags().if_less << std::endl;
        std::cout << "if_not_greater_or_equal: " << reg::RegX[Rindex].getStatFlags().if_not_greater_or_equal << '\n';
        std::cout << "if_less_or_equal: " << reg::RegX[Rindex].getStatFlags().if_less_or_equal << '\n';
        std::cout << "if_not_greater: " << reg::RegX[Rindex].getStatFlags().if_not_greater << std::endl;

        return;
    }
    void statstack(std::uint16_t sIndex) {
        auto& regi = reg::sstack[sIndex];
        std::cout << "stack: " << "x" << sIndex << '\n';
        std::cout << "Stack Size: " << reg::sstack.size() << '\n';

        std::string currentMode;
        switch (regi.getCurrentMode()) {
            case reg::r_16:
                currentMode = "16-bit";
                std::cout << "Data: " << regi.getData().bit16 << '\n';
                break;
            case reg::r_32:
                currentMode = "32-bit";
                std::cout << "Data: " << regi.getData().bit32 << '\n';
                break;
            case reg::r_64:
                currentMode = "64-bit";
                std::cout << "Data: " << regi.getData().bit64 << '\n';
                break;
            case reg::r_string:
                currentMode = "String";
                std::cout << "Data: " << regi.getString() << '\n';
                break;
            case reg::r_pointer:
                currentMode = "Pointer";
                std::cout << "Data: " << regi.getData().ptr << '\n';
                break;
            case reg::r_nill:
                currentMode = "Nill";
                break;
        }
        std::cout << "Current Mode: " << currentMode << '\n';
        std::cout << "if_equal: " << regi.getStatFlags().if_equal << '\n';
        std::cout << "if_zero: " << regi.getStatFlags().if_zero << '\n';
        std::cout << "if_not_equal: " << regi.getStatFlags().if_not_equal << '\n';
        std::cout << "if_not_zero: " << regi.getStatFlags().if_not_zero << '\n';
        std::cout << "if_greater: " << regi.getStatFlags().if_greater << '\n';
        std::cout << "if_not_less_or_equal: " << regi.getStatFlags().if_not_less_or_equal << '\n';
        std::cout << "if_greater_or_equal: " << regi.getStatFlags().if_greater_or_equal << '\n';
        std::cout << "if_not_less: " << regi.getStatFlags().if_not_less << '\n';
        std::cout << "if_less: " << regi.getStatFlags().if_less << std::endl;
        std::cout << "if_not_greater_or_equal: " << regi.getStatFlags().if_not_greater_or_equal << '\n';
        std::cout << "if_less_or_equal: " << regi.getStatFlags().if_less_or_equal << '\n';
        std::cout << "if_not_greater: " << regi.getStatFlags().if_not_greater << std::endl;

    }
    void halt() {
        #ifdef __x86_64__
            __asm__(".intel_syntax noprefix");
            __asm__("looplz: ");
            __asm__("nop");
            __asm__("nop");
            __asm__("jmp looplz");
            __asm__(".att_syntax");
            
        #else 
            while (true) {}
        #endif

    }
}