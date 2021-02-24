#ifndef POW_TEST_HPP
#define POW_TEST_HPP

#include "gtest/gtest.h"

#include "../classes/Pow.hpp"
#include "../classes/Op.hpp"

TEST(PowTest, PowEvaluatePos)
{
    Op* op1 = new Op(3);
    Op* op2 = new Op(2);
    Pow* test = new Pow(op1, op2);
    EXPECT_EQ(test->evaluate(), 9);
}

TEST(PowTest, PowEvaluateNegative)
{
        Op* op1 = new Op(-2);
        Op* op2 = new Op(3);
        Pow* test = new Pow(op1, op2);
        EXPECT_EQ(test->evaluate(), -8);
}

TEST(PowTest, PowEvaluateWithAnotherClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Sub* subtract = new Sub(op1, op2);
        Op* op3 = new Op(5);
        Pow* test = new Pow(op3, subtract);
        EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowEvaluateWithMockClass)
{
        Op* op1 = new Op(2);
        Op* op2 = new Op(2);
        Mult* mult = new Mult(op1, op2);
        Op* op3 = new Op(2);
        Pow* test = new Pow(op3, mult);
        EXPECT_EQ(test->evaluate(), 16);
}

TEST(PowTest, PowStringifyTest)
{
    Op* op1 = new Op(8);
    Op* op2 = new Op(9);
    Pow* test = new Pow(op1, op2);
    EXPECT_EQ(test->stringify(), "8.000000**9.000000");
}

TEST(PowTest, PowStringifyWithAnotherClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Sub* subtract = new Sub(op1, op2);
        Op* op3 = new Op(5);
        Pow* test = new Pow(op3, subtract);
        EXPECT_EQ(test->stringify(), "5.000000**5.000000-5.000000");
}


#endif //POW_TEST_HPP
