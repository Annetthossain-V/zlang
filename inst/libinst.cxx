#include "../inc.H"
#include <cstdint>

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

    }
    void halt() {
        #ifdef __x86_64__
            __asm__(".intel_syntax noprefix");
            __asm__("looplz: ");
            __asm__("nop");
            __asm__("nop");
            __asm__("jmp looplz");
            __asm__("hlt");
            __asm__(".att_syntax");
            
        #else 
            while (true) {}
        #endif

    }
    void mov(std::uint16_t Register1, std::uint16_t Register2, bool dualRegister, double IntegerContent, char* StringContent, bool RegisterString) {
        if (RegisterString) {

            if (reg::RegX[Register1].getCurrentMode() != reg::r_string) runtime::panic("mov string to non string mode register");

            std::string data(StringContent);
            reg::RegX[Register1].editStringSection(data);

            return;
        }
        if (!dualRegister) {
            // reg reg
            reg::RegX[Register1] = reg::RegX[Register2];
            return;
        } else if (dualRegister) {
            // reg number
            switch (reg::RegX[Register1].getCurrentMode()) {
                case reg::r_16:
                    reg::RegX[Register1].editDataSection((std::int16_t) IntegerContent, 0, 0);
                    return;
                
                case reg::r_32:
                    reg::RegX[Register1].editDataSection(0, (std::int32_t) IntegerContent, 0);
                    return;
                
                case reg::r_64:
                    reg::RegX[Register1].editDataSection(0, 0, IntegerContent);
                    return;
                
                default:
                    runtime::panic("Instruction Error");
            }
        }
    }
}