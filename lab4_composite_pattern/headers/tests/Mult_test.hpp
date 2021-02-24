#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include <gtest/gtest.h>
#include <vector>
#include "../classes/Mult.hpp"
#include "../classes/Op.hpp"

class MultTests: public ::testing::Test {
public:
    std::vector<Base*> operands;
    Base* mult;
    MultTests() {
        for (int i = 0; i < 4; i++) {
            operands.push_back(new Op(double(i)));
        }
    }
    ~MultTests(){
        for(auto ops : operands){
            delete ops;
        }
        delete mult;
    }
};

TEST_F(MultTests, MultBasicOperationTest){
    mult = new Mult(operands[2], operands[3]);
    EXPECT_EQ(mult->evaluate(), operands[2]->evaluate() * operands[3]->evaluate());
}

TEST_F(MultTests, MultZeroMultiplication) {
    mult = new Mult(operands[3], operands[0]);
    ASSERT_EQ(mult->evaluate(),operands[0]->evaluate());
}

TEST_F(MultTests, MultOneMultiplication){
    mult = new Mult(operands[3],operands[1]);
    ASSERT_EQ(mult->evaluate(), operands[3]->evaluate());
}

TEST_F(MultTests, MultBasicStr){
    mult = new Mult(operands[2], operands[3]);
    EXPECT_EQ(mult->stringify(), "(" + operands[2]->stringify() + " * " + operands[3]->stringify() + ")");
}

#endif // __MULT_TEST_HPP__
