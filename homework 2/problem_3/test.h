#ifndef TEST_H
#define TEST_H

// this function tests both the area and perimeter calculations for the circular card
template<typename T>
bool testCircularCard(T radius);

// this function tests both the area and perimeter calculations for the rectangle card
template<typename T>
bool testRectangularCard(T width, T height);

// tests various data types for the circular card class
void testCircle();

// tests various data types for the rectangular card class
void testRectangle();

#endif // TEST_H
