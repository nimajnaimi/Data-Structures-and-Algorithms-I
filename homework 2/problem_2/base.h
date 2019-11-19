#ifndef BASE_H
#define BASE_H
#include<iostream>
using namespace std;

class Base {
    public:
        virtual void print();

        void show();

        // why is this destructor virtual?
        virtual ~Base() {
            cout<< "~Base() called" <<endl;
        }
};

#endif // BASE_H
