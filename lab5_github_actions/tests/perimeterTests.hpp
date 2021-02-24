#ifndef PERIMETERTEST_HPP
#define PERIMETERTEST_HPP

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(RectanglePerimeterTests, PerimeterSpecificValues) 
{
	Rectangle* rectangle = new Rectangle();
	rectangle->set_width(3);
	rectangle->set_height(4);
	EXPECT_EQ(rectangle->perimeter(), 14);
	rectangle->set_width(4);
	rectangle->set_height(6);
	EXPECT_EQ(rectangle->perimeter(), 20);
	rectangle->set_width(10);
	rectangle->set_height(10);
	EXPECT_EQ(rectangle->perimeter(), 40);
}

TEST(RectanglePerimeterTests, PerimeterEvaluateZero) 
{
	Rectangle* rectangle = new Rectangle(0, 0);
	EXPECT_EQ(rectangle->perimeter(), 0);
}

TEST(RectanglePerimeterTests, PerimeterEvaluatePositive) 
{
	Rectangle* rectangle = new Rectangle(4, 5);
	EXPECT_TRUE(rectangle->area() >= 0);
}

TEST(RectanglePerimeterTests, PerimeterEvaluateNegative) 
{
	Rectangle* rectangle = new Rectangle(4, -5);
	EXPECT_TRUE(rectangle->perimeter() < 0);
}

#endif