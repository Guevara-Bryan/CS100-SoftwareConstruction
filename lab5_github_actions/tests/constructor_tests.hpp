#ifndef CONSTRUCTOR_TESTS_HPP
#define CONSTRUCTOR_TESTS_HPP

#include "../header/rectangle.hpp"
#include "gtest/gtest.h"


TEST(RectangleConstructorTests, BasicConstAreaEvaluateCorrectly) 
{
	Rectangle rectangle;
	EXPECT_EQ(1, rectangle.area());
}

TEST(RectangleConstructorTests, BasicConstPerEvaluateCorrectly) 
{
	Rectangle* rectangle = new Rectangle();
	EXPECT_EQ(rectangle->perimeter(), 4);
}

TEST(RectangleConstructorTests, ConstAreaEvaluateCorrectly) 
{
	Rectangle* rectangle = new Rectangle(4, 5);
	EXPECT_TRUE(rectangle->area() >= 0);
}

TEST(RectangleConstructorTests, ConstPerimeterEvaluateCorrectly) 
{
	Rectangle* rectangle = new Rectangle(4, 5);
	EXPECT_TRUE(rectangle->perimeter() >= 0);
}

#endif

