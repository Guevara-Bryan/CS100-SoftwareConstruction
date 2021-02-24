#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include <gtest/gtest.h>

#include "../classes/Rand.hpp"

class RandTests: public ::testing::Test{
public:
    Base* random = new Rand();

    ~RandTests(){
        delete random;
    }
};

//--- Evaluating non-zero values
TEST_F(RandTests, RandLowerBound) {
    EXPECT_TRUE(random->evaluate() >= 0);
}

TEST_F(RandTests, RandUpperBound) {
    EXPECT_TRUE(random->evaluate() < 100);
}

TEST_F(RandTests, RandNotEmptyString){    
    EXPECT_FALSE(random->stringify() == "");
}

#endif // __RAND_TEST_HPP__
