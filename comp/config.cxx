#include "config.hxx"
#include <iostream>


namespace config {
    conf Conf;

    void conf::init() {
        this->cFlags.if_equal = false;
        this->cFlags.if_zero = false;
        this->cFlags.if_not_equal = false;
        this->cFlags.if_not_zero = false;
        this->cFlags.if_greater = false;
        this->cFlags.if_not_less_or_equal = false;
        this->cFlags.if_greater_or_equal = false;
        this->cFlags.if_not_less = false;
        this->cFlags.if_less = false;
        this->cFlags.if_not_greater_or_equal = false;
        this->cFlags.if_less_or_equal = false;
        this->cFlags.if_not_greater = false;
    }

    void conf::print() {

        std::cout << "if_equal: " << this->cFlags.if_equal << '\n';
        std::cout << "if_zero: " << this->cFlags.if_zero << '\n';
        std::cout << "if_not_equal: " << this->cFlags.if_not_equal << '\n';
        std::cout << "if_not_zero: " << this->cFlags.if_not_zero << '\n';
        std::cout << "if_greater: " << this->cFlags.if_greater << '\n';
        std::cout << "if_not_less_or_equal: " << this->cFlags.if_not_less_or_equal << '\n';
        std::cout << "if_greater_or_equal: " << this->cFlags.if_greater_or_equal << '\n';
        std::cout << "if_not_less: " << this->cFlags.if_not_less << '\n';
        std::cout << "if_less: " << this->cFlags.if_less << std::endl;
        std::cout << "if_not_greater_or_equal: " << this->cFlags.if_not_greater_or_equal << '\n';
        std::cout << "if_less_or_equal: " << this->cFlags.if_less_or_equal << '\n';
        std::cout << "if_not_greater: " << this->cFlags.if_not_greater << std::endl;


    }

}