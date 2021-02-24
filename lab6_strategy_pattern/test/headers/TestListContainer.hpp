#ifndef TESTLISTCONTAINER_HPP
#define TESTLISTCONTAINER_HPP

#include "../../headers/ListContainer.hpp"
#include "../../headers/SelectionSort.hpp"
#include "../../includes/CompositeClasses/classes_bits.hpp"
#include "../../headers/bubblesort.hpp"

class TestListContainer : public ::testing::Test{
public:
    ListContainer* list;
    TestListContainer(): list(new ListContainer){}
    ~TestListContainer(){
        delete list;
    }
};

TEST_F(TestListContainer, AddElementTest){
    Base* one = new Op(1);
    list->add_element(one);

    ASSERT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0)->evaluate(), one->evaluate());
}

TEST_F(TestListContainer, SetSortFunctionTest){
    EXPECT_THROW(list->sort(), std::runtime_error);
}

TEST_F(TestListContainer, AtFunctionTest){
    list->add_element(new Op(3));
    list->add_element(new Op(2));
    list->add_element(new Op(8));

    ASSERT_TRUE(list->at(0)->evaluate() == double(3));
    ASSERT_TRUE(list->at(1)->evaluate() == double(2));
    ASSERT_TRUE(list->at(2)->evaluate() == double(8));
}

TEST_F(TestListContainer, SizeFunctionTest){
    list->add_element(new Op(1));
    list->add_element(new Op(2));
    list->add_element(new Op(3));
    list->add_element(new Op(4));

    ASSERT_EQ(list->size(), 4);
}

TEST_F(TestListContainer, SelectionSortFunctionTest){

    list->set_sort_function(new SelectionSort);
    
    list->add_element(new Op(23));
    list->add_element(new Op(11));
    list->add_element(new Op(46));
    list->add_element(new Op(2));

    list->sort();

    bool sorted = true;
    for(int i = 0; i < list->size()-1; i++){
        if(list->at(i)->evaluate() > list->at(i+1)->evaluate()){
            sorted = false;
            break;
        }
    }

    ASSERT_TRUE(sorted);
}

TEST_F(TestListContainer, BubbleSortFunctionTest){

    list->set_sort_function(new BubbleSort);
    
    list->add_element(new Op(23));
    list->add_element(new Op(11));
    list->add_element(new Op(46));
    list->add_element(new Op(2));

    list->sort();

    bool sorted = true;
    for(int i = 0; i < list->size()-1; i++){
        if(list->at(i)->evaluate() > list->at(i+1)->evaluate()){
            sorted = false;
            break;
        }
    }

    ASSERT_TRUE(sorted);
}


TEST_F(TestListContainer, SwapFunctionTest){
    list->add_element(new Op(2));
    list->add_element(new Op(4));
    list->swap(0,1);

    ASSERT_EQ(list->at(0)->evaluate(), double(4));
    ASSERT_EQ(list->at(1)->evaluate(), double(2));
}
#endif // TESTLISTCONTAINER_HPP