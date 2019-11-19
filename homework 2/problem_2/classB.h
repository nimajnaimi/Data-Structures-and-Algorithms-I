#ifndef CLASSB_H
#define CLASSB_H

#include "base.h"

class DerivedB : public Base {
    int *ptr;

    public:
        DerivedB(int size);

        void print();

        void show();

        ~DerivedB() {
            delete []ptr;
            cout<< "~DerivedB() called" <<endl;
        }
};

#endif // CLASSB_H
