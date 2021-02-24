#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include <gtest/gtest.h>
#include <vector>

#include "../classes/Op.hpp"

// Test fixture to test different options
class OpTests : public ::testing::Test {
public:
    std::vector<Base*> operands;
    OpTests() {
        operands.push_back(new Op(8));
        operands.push_back(new Op(0));
        operands.push_back(new Op());
    }

    ~OpTests() {
        for (auto a: operands){
            delete a;
        }
    }
};

//--- Evaluating non-zero values
TEST_F(OpTests, OpEvaluateNonZero) {
    EXPECT_EQ(operands[0]->evaluate(), 8);
}

TEST_F(OpTests, OpStringifyNonZero) {
    EXPECT_EQ(operands[0]->stringify(), std::to_string(double(8)));
}

//--- Evaluating zero items when passed as arguments on constructor.
TEST_F(OpTests, OpZeroAsArgument){
    EXPECT_EQ(operands[1]->evaluate(), 0);
}

TEST_F(OpTests, OpZeroAsArgumentStr){
    EXPECT_EQ(operands[1]->stringify(), std::to_string(double(0)));
}

//--- Evaluating zero items when no argument is passed on constructor.
TEST_F(OpTests, OpZeroNoArgument){
    EXPECT_EQ(operands[2]->evaluate(), 0);
}

TEST_F(OpTests, OpZeroNoArgumentStr){
    EXPECT_EQ(operands[2]->stringify(), std::to_string(double(0)));
}


#endif //__OP_TEST_HPP__
