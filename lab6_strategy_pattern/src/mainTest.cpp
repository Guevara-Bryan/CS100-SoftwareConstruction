#include <iostream>
#include "../headers/vectorcontainer.hpp"
#include "../headers/ListContainer.hpp"
#include "../headers/SelectionSort.hpp"
#include "../includes/CompositeClasses/classes_bits.hpp"
#include "../includes/lab06/sort.hpp"
#include "../headers/bubblesort.hpp"

int main()
{
    //VectorContainer Tests
    VectorContainer* test_container1 = new VectorContainer();
    VectorContainer* test_container2 = new VectorContainer();
    test_container1->set_sort_function(new BubbleSort);
    test_container2->set_sort_function(new SelectionSort());

    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Op* four = new Op(4);
    Op* five = new Op(5);
    Op* ten = new Op(10);
    Op* fiveteen = new Op(15);

    Mult* t1 = new Mult(three, four);
    Sub* t2 = new Sub(ten, three);
    Add* t3 = new Add(ten, five);
    Div* t4 = new Div(fiveteen, t3);

    test_container1->add_element(two);
    test_container1->add_element(t1);
    test_container1->add_element(t2);
    test_container1->add_element(t3);
    test_container1->add_element(t4);
    test_container1->add_element(one);

    test_container2->add_element(two);
    test_container2->add_element(t1);
    test_container2->add_element(t2);
    test_container2->add_element(t3);
    test_container2->add_element(t4);
    test_container2->add_element(one);

    std::cout << "Vector container Bubblesort test: " << std::endl;
    std::cout << "Pre-sorted Vector container: \n";
    test_container1->print();
    std::cout << "\n";
    std::cout << "Sorted Vector container: \n";
    test_container1->sort();
    test_container1->print();
    std::cout << "\n" << std::endl;

    std::cout << "Vector container Selection test: " << std::endl;
    std::cout << "Pre-sorted Vector container: \n";
    test_container2->print();
    std::cout << "\n";
    std::cout << "Sorted Vector container: \n";
    test_container2->sort();
    test_container2->print();
    std::cout << "\n" << std::endl;

    // List Container Tests
    ListContainer* test_container3 = new ListContainer();
    ListContainer* test_container4 = new ListContainer();
    test_container3->set_sort_function(new BubbleSort);
    test_container4->set_sort_function(new SelectionSort());

    test_container3->add_element(two);
    test_container3->add_element(t1);
    test_container3->add_element(t2);
    test_container3->add_element(t3);
    test_container3->add_element(t4);
    test_container3->add_element(one);

    test_container4->add_element(two);
    test_container4->add_element(t1);
    test_container4->add_element(t2);
    test_container4->add_element(t3);
    test_container4->add_element(t4);
    test_container4->add_element(one);

    std::cout << "List container Bubblesort test: " << std::endl;
    std::cout << "Pre-sorted list container: \n";
    test_container3->print();
    std::cout << "\n";
    std::cout << "Sorted list container: \n";
    test_container3->sort();
    test_container3->print();
    std::cout << "\n \n" << std::endl;

    std::cout << "List container SelectionSort test: " << std::endl;
    std::cout << "Pre-sorted list container: \n";
    test_container4->print();
    std::cout << "\n";
    std::cout << "Sorted list container: \n";
    test_container4->sort();
    test_container4->print();
    std::cout << "\n" << std::endl;
    

}
