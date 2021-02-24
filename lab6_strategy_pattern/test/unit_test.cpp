
#include <gtest/gtest.h>

#include "headers/vectorctests.hpp"
#include "headers/bubblesorttests.hpp"
#include "headers/TestListContainer.hpp"
#include "headers/selectionvectortests.hpp"


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}