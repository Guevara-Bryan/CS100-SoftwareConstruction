#ifndef __DIV_TEST_HPP
#define __DIV_TEST_HPP__

#include <gtest/gtest.h>
#include <vector>
#include "../classes/Div.hpp"
#include "../classes/Op.hpp"

class DivTests: public ::testing::Test {
public:
    std::vector<Base*> operands;
    Base*div;
    DivTests() {
        operands.push_back(new Op(0));
        operands.push_back(new Op(1));
        operands.push_back(new Op(12));
        operands.push_back(new Op(3));
    }
    ~DivTests(){
        for(auto ops : operands){
            delete ops;
        }
        delete div;
    }
};

TEST_F(DivTests, DivBasicOperationTest){
    div = new Div(operands[2], operands[3]);
    EXPECT_EQ(div->evaluate(), operands[2]->evaluate() / operands[3]->evaluate());
}

TEST_F(DivTests, DivByZeroDivision) {
    div = new Div(operands[3], operands[0]);
    EXPECT_THROW(div->evaluate(), std::runtime_error);
}

TEST_F(DivTests, DivByOneDivision){
    div = new Div(operands[3],operands[1]);
    ASSERT_EQ(div->evaluate(), operands[3]->evaluate());
}

TEST_F(DivTests, DivBasicStr){
    div = new Div(operands[2], operands[3]);
    EXPECT_EQ(div->stringify(), "(" + operands[2]->stringify() + " / " + operands[3]->stringify() + ")");
}

#endif
