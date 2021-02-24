#ifndef ADD_TEST_HPP
#define ADD_TEST_HPP

#include "gtest/gtest.h"

#include "../classes/Add.hpp"
#include "../classes/Sub.hpp"
#include "../classes/Op.hpp"

TEST(AddTest, AddEvaluatePosTrue)
{
    Op* op1 = new Op(8);
    Op* op2 = new Op(9);
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), 17);
   // EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddEvaluateZero)
{
	Op* op1 = new Op(-10.0);
	Op* op2 = new Op(10.0);
	Add* test = new Add(op1, op2);
	EXPECT_EQ(test->evaluate(), 0);
	//EXPECT_EQ(test->evaluate(), 10);
}

TEST(AddTest, AddEvaluateNegativeTrue)
{
	Op* op1 = new Op(-10.0);
        Op* op2 = new Op(5);
        Add* test = new Add(op1, op2);
        EXPECT_EQ(test->evaluate(), -5);
	//EXPECT_EQ(test->evaluate(), 5);
}

TEST(AddTest, AddEvaluateWithAnotherClassTrue)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
	Sub* subtract = new Sub(op1, op2);
	Op* op3 = new Op(5);
        Add* test = new Add(op3, subtract);
        EXPECT_EQ(test->evaluate(), 5);
	//EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddEvaluateWithMockClass)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Mult* mult = new Mult(op1, op2);
        Op* op3 = new Op(5);
        Add* test = new Add(op3, mult);
        EXPECT_EQ(test->evaluate(), 30);
        //EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringifyTest)
{
    Op* op1 = new Op(8);
    Op* op2 = new Op(9);
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "8.000000+9.000000");
   // EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringifyWithAnotherClassTrue)
{
        Op* op1 = new Op(5);
        Op* op2 = new Op(5);
        Sub* subtract = new Sub(op1, op2);
        Op* op3 = new Op(5);
        Add* test = new Add(op3, subtract);
        EXPECT_EQ(test->stringify(), "5.000000+5.000000-5.000000");
        //EXPECT_EQ(test->evaluate(), 0);
}


#endif //ADD_TEST_HPP

