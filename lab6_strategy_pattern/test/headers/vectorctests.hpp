#ifndef VECTORCTESTS_HPP
#define VECTORCTESTS_HPP

#include <gtest/gtest.h>
#include "../../headers/vectorcontainer.hpp"
#include "../../includes/CompositeClasses/Op.hpp"
#include "../../includes/CompositeClasses/Add.hpp"

TEST(VectorContainerTestSet, ContainerAddElementTest) {
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);

    Op* one = new Op(1);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(1)->evaluate(), 1);

    Add* plus = new Add(one, seven);
    test_container->add_element(plus);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(2)->evaluate(), 8);

    Add* plus2 = new Add(one, plus);
    test_container->add_element(plus2);

    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(3)->evaluate(), 9);

}

TEST(VectorContainerTestSet, ContainerStringifyTest) {
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->stringify(), "7.000000");

    Op* one = new Op(1);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(1)->stringify(), "1.000000");

    Add* plus = new Add(one, seven);
    test_container->add_element(plus);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(2)->stringify(), "(1.000000 + 7.000000)");

    Add* plus2 = new Add(one, plus);
    test_container->add_element(plus2);

    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(3)->stringify(), "(1.000000 + (1.000000 + 7.000000))");

}

TEST(VectorContainerTestSet, ContainerSwapTest) {
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);

    Op* one = new Op(1);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 1);

    test_container->swap(0, 1);

    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);

    Add* plus = new Add(one, seven);
    test_container->add_element(plus);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(2)->evaluate(), 8);

    test_container->swap(0, 2);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 8);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);
}

#endif