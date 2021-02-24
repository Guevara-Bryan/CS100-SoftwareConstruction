#include <gtest/gtest.h>

#include "../header/rectangle.hpp"

class RectangleAreaTests : public testing::Test {
public:
    Rectangle* rectangle;

    ~RectangleAreaTests() {
        delete rectangle;
    }
};

TEST_F(RectangleAreaTests, AreaWithNoParams){
    rectangle = new Rectangle();        // No parameters w & h should be 1.
    EXPECT_EQ(rectangle->area(),1);
}

TEST_F(RectangleAreaTests, AreaWithParams){
    rectangle = new Rectangle(3,4);     // Rectangle with params should return w*h.
    EXPECT_EQ(rectangle->area(), 12);

}

TEST_F(RectangleAreaTests, AreaZeroAsParams){
    rectangle = new Rectangle(0,0);
    EXPECT_EQ(rectangle->area(), 0);
}

TEST_F(RectangleAreaTests, AreaNegativeNumbers){
    rectangle = new Rectangle(-3,2);
    EXPECT_EQ(rectangle->area(), -6);       // No specifications given for the lengths so negative values are possible.
}

TEST_F(RectangleAreaTests, AreaBothNegativeNumbers){
    rectangle = new Rectangle(-3,-3);
    EXPECT_EQ(rectangle->area(), 9);       // No specifications given for the lengths so negative values are possible.
}