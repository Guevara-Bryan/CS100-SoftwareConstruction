#include <gtest/gtest.h>


#include "constructor_tests.hpp"
#include "BTests.hpp"
#include "perimeterTests.hpp"


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}