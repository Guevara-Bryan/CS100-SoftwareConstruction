#include <gtest/gtest.h>

#include "../headers/tests/Tests.hpp" // Testt.hpp #includes the files for all the tests

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
