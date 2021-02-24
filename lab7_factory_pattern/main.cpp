#include <iostream>
#include "ExpressionCalculator.hpp"

int main(int argc, char** argv){

    ExpressionCalculator calculate;
    Base* calc = calculate.parse(argv, argc);
    std::cout << calc->stringify() << " = " << calc->evaluate() << std::endl;
    return 0;
}