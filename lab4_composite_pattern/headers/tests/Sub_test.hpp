#ifndef SUB_TEST_HPP
#define SUB_TEST_HPP

#include "gtest/gtest.h"

#include "../classes/Sub.hpp"
#include "../classes/Op.hpp"

TEST(SubTest, SubEvaluatePos)
{
    Op* op1 = new Op(10);
    Op* op2 = new Op(5);
    Sub* test = new Sub(op1, op2);
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(SubTest, SubEvaluateZero)
{
        Op* op1 = new Op(10.0);
        Op* op2 = new Op(10.0);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubEvaluateNegative)
{
        Op* op1 = new Op(5.0);
        Op* op2 = new Op(10.0);
        Sub* test = new Sub(op1, op2);
        EXPECT_EQ(test->evaluate(), -5);
}

TEST(SubTest, SubEvaluateWithAnotherClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Add* add = new Add(op1, op2);
        Op* op3 = new Op(5);
        Sub* test = new Sub(op3, add);
        EXPECT_EQ(test->evaluate(), -5);
}

TEST(SubTest, SubEvaluateWithMockClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Mult* mult = new Mult(op1, op2);
        Op* op3 = new Op(5);
        Sub* test = new Sub(op3, mult);
        EXPECT_EQ(test->evaluate(), -20);
}

TEST(SubTest, SubStringifyTest)
{
    Op* op1 = new Op(8);
    Op* op2 = new Op(9);
    Sub* test = new Sub(op1, op2);
    EXPECT_EQ(test->stringify(), "8.000000-9.000000");
}

TEST(SubTest, SubStringifyWithAnotherClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Sub* subtract = new Sub(op1, op2);
        Op* op3 = new Op(5);
        Sub* test = new Sub(op3, subtract);
        EXPECT_EQ(test->stringify(), "5.000000-5.000000-5.000000");
}


#endif //SUB_TEST_HPP
