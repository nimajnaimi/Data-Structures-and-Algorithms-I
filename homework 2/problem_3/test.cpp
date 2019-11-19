#include "circular_card.h"
#include "rectangular_card.h"
#include "test.h"
#include<iostream>
using namespace std;

// this function tests both the area and perimeter
// calculations for the circular card
template<typename T>
bool testCircularCard(T radius) {
    circular_card<T> cc(radius);
    card<T> *pc = &cc;

    // checks that area was calculated correctly
    if (pc->area() != (T)(PI * radius * radius)) {
        cout << "testCircularCard(" << radius <<
            "): FAILED, calculated area: " << pc->area() << endl;
        return false;
    }

    // checks that the perimeter was calculated correctly
    if (pc->perimeter() != (T)(PI * 2 * radius)) {
        cout << "testCircularCard(" << radius <<
            "): FAILED, calculated perimeter: " << pc->perimeter() << endl;
        return false;
    }

    return true;
}

// this function tests both the area and perimeter
// calculations for the rectangle card
template<typename T>
bool testRectangularCard(T width, T height) {
    rectangular_card<T> rc(width, height);
    card<T> *pc = &rc;

    // checks that area was calculated correctly
    if (pc->area() != width * height) {
        cout << "testRectangularCard(" << width << ", " << height <<
            "): FAILED, calculated area:" << pc->area() << "\n";
        return false;
    }

    // checks that the perimeter was calculated correctly
    if (pc->perimeter() != 2 * width + 2 * height) {
        cout << "testRectangularCard(" << width << ", " << height <<
            "): FAILED, calculated perimeter:" << pc->perimeter() << "\n";
        return false;
    }

    return true;
}

// tests 0, int, and double size values
void testRectangle() {
    if (!testRectangularCard(0, 0) ||
        !testRectangularCard(2, 3) ||
        !testRectangularCard(2.5, 3.5)) {
        cout << "testRectangularCard(): FAILED\n";
    }

    cout << "testRectangularCard(): PASSED\n";
}

// tests 0, int, and double radius values
void testCircle() {
    if (!testCircularCard(0) ||
        !testCircularCard(5) ||
        !testCircularCard(2.3)) {
        cout << "testCircularCard(): FAILED\n";
    }

    cout << "testCircularCard(): PASSED\n";
}

int main() {
    testRectangle();
    testCircle();
}


