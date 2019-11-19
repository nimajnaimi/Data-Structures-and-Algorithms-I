#include "classA.h"
#include<iostream>
using namespace std;

DerivedA::DerivedA(int size) {
    printf("new Derived A obj\n");
    ptr = (size>0) ? new int[size] : nullptr;
}

void DerivedA::print() {
    cout<< "print(virtual) DerivedA class" <<endl;
}

void DerivedA::show() {
    cout<< "show(non-virtual) in DerivedA class" <<endl;
}
