#include "base.h"
#include<iostream>
using namespace std;

void Base::print() {
    cout<< "print(virtual) in Base class" <<endl;
}

void Base::show() {
    cout<< "show(non-virtual) in Base class" <<endl;
}
