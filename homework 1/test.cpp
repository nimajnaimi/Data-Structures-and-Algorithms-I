//.....Name: Nima Naimi
//.....Date: October 4th, 2019
//.....Homework #1

#include <iostream>
#include "test.h"

/*
 * test MyArray::add()
 */
void testAdd() {
    // create an object of MyArray
    MyArray<int> arr(10);

    // add values to the array
    for (int i = 0; i < 5; i++) {
        arr.add(i);
    }

    // check the size of the array
    if (arr.count() != 5) {
        printf("testAdd: FAILED, expected:%d, actual:%d\n", 5, arr.count());
        return;
    }

    // check the array values are correct
    for (int i = 0; i < arr.count(); i++) {
        if (arr[i] != i) {
            printf("testAdd: FAILED, values added to array are not correct\n");
            return;
        }
    }

    printf("testAdd: PASSED\n");
}

/*
 * test MyArray::sort()
 */
void testSort() {
    // create an object of MyArray
    MyArray<int> arr(10);
    int counter[10] = {};
    int counter2[10] = {};

    // test empty array
    try {
        arr.sort();
    } catch(...) {
        printf("testSort(): FAILED, error when testing empty array\n");
    }

    // add random elements to the array
    for (int i = 0; i < 10; i++) {
        int j = std::rand() % 10;
        arr.add(j);
        counter[j]++; // log what numbers are added
    }

    arr.sort();

    // log what numbers are in the sorted array
    for (int i = 0; i < 10; i++) {
        counter2[arr[i]]++;
    }

    // check the array is sorted in ascending order
    for (int i = 0; i < arr.count() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("testSort(): FAILED, array isn't sorted in ascending order\n");
            return;
        }
    }

    // check the sorted array has the same values as the original
    for (int i = 0; i < 10; i++) {
        if (counter[i] != counter2[i]) {
            printf("testSort(): FAILED, array elements were changed\n");
            return;
        }
    }

    printf("testSort(): PASSED\n");
}

/*
 * test MyArray::reverse()
 */
void testReverse() {
    // create an object of MyArray
    MyArray<int> arr(10);
    MyArray<int> arr2(10);

    // test empty array
    try {
        arr.reverse();
    } catch(...) {
        printf("testReverse(): FAILED, error encountered\n");
    }

    // add random elements to the array
    for (int i = 0; i < 10; i++) {
        int j = std::rand() % 10;
        arr.add(j);
        arr2.add(j);
    }

    arr.reverse();

    // check array contents were reversed properly
    for (int i = 0; i < arr.count(); i++) {
        if (arr[i] != arr2[arr2.count() - 1 - i]) {
            printf("testReverse(): FAILED, array wasn't reversed correctly\n");
            return;
        }
    }

    printf("testReverse(): PASSED\n");
}

/*
 * test MyArray::[]
 */
void testSubscriptOperator() {
    // create an object of MyArray
    MyArray<int> arr(10);

    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    int testCount = 5, testPassed = 0;
    for (int i = 0; i < testCount; i++) {
        if (arr[i] != i) {
            break;
        } else {
            testPassed++;
        }
    }

    if (testPassed == testCount) {
        printf("testSubscriptOperator: PASSED\n");
    } else {
        printf("testSubscriptOperator: FAILED\n");
    }
}
