//.....Name: Nima Naimi
//.....Date: October 4th, 2019
//.....Homework #1

#include <iostream>
#include "test.h"

//forward declaration
void testReverse();
void testSort();
void testAdd();
void testSubscriptOperator();

int main() {
    std::cout << "Hello, World!" << std::endl;

    // run tests
    testSubscriptOperator();
    testAdd();
    testSort();
    testReverse();
}
