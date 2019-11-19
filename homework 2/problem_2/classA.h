#ifndef CLASSA_H
#define CLASSA_H

#include "base.h"

class DerivedA : public Base {
    int *ptr;

    public:
        DerivedA(int size);

        void print();

        void show();

        ~DerivedA() {
            delete []ptr;
            cout<< "~DerivedA() called" <<endl;
        }
};


#endif // CLASSA_H
