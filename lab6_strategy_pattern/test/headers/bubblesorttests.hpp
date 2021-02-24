#ifndef BUBBLESORTTESTS_HPP
#define BUBBLESORTTESTS_HPP

#include <gtest/gtest.h>
#include "../../headers/vectorcontainer.hpp"
#include "../../includes/CompositeClasses/Op.hpp"
#include "../../includes/CompositeClasses/Add.hpp"
#include "../../includes/CompositeClasses/Mult.hpp"
#include "../../includes/CompositeClasses/Sub.hpp"
#include "../../includes/CompositeClasses/Pow.hpp"
#include "../../includes/CompositeClasses/Div.hpp"
#include "../../headers/bubblesort.hpp"


TEST(BubblesortTestSet, BubbleSortTest1)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}


TEST(BubblesortTestSet, BubbleSortTest2)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    Op* nine = new Op(9);
    Op* eight = new Op(8);
    Mult* TreeD = new Mult(nine, eight);

    //Op* three = new Op(3);
    //Op* two = new Op(2);
    Pow* TreeE = new Pow(three, two);

    //Op* ten = new Op(10);
    //Op* two = new Op(2);
    Div* TreeF = new Div(ten, two);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    container->add_element(TreeD);
    container->add_element(TreeE);
    container->add_element(TreeF);

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
    EXPECT_EQ(container->at(3)->evaluate(), 72);
    EXPECT_EQ(container->at(4)->evaluate(), 9);
    EXPECT_EQ(container->at(5)->evaluate(), 5);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 5);
    EXPECT_EQ(container->at(3)->evaluate(), 9);
    EXPECT_EQ(container->at(4)->evaluate(), 28);
    EXPECT_EQ(container->at(5)->evaluate(), 72);
}

TEST(BubblesortTestSet, BubbleSortTest3)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    Op* nine = new Op(9);
    Mult* TreeD = new Mult(nine, TreeA);

    //Op* three = new Op(3);
    //Op* two = new Op(2);
    Pow* TreeE = new Pow(TreeB, two);

    //Op* ten = new Op(10);
    //Op* two = new Op(2);
    Div* TreeF = new Div(TreeD, TreeE);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    container->add_element(TreeD);
    container->add_element(TreeE);
    container->add_element(TreeF);

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
    EXPECT_EQ(container->at(3)->evaluate(), 252);
    EXPECT_EQ(container->at(4)->evaluate(), 25);
    EXPECT_EQ(container->at(5)->evaluate(), 10.08);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 10.08);
    EXPECT_EQ(container->at(3)->evaluate(), 25);
    EXPECT_EQ(container->at(4)->evaluate(), 28);
    EXPECT_EQ(container->at(5)->evaluate(), 252);
}

#endif