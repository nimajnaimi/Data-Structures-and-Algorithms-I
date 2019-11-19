#include <iostream>
#include <ctime>
#include "MyMatrix.h"
#include "test.h"

// tests the adding function of MyMatrix
void testAdd() {
    srand(time(NULL));
    int width = 5;
    int height = 6;
    double arr[width * height];

    // fill matrices with random values
    for (int i = 0; i < width * height; i++) {
        arr[i] = (double)std::rand() / 1000;
    }

    MyMatrix<double> matrix1(width, height, arr);
    MyMatrix<double> matrix2(width, height, arr);
    matrix1.Add(matrix2);

    // check the matrices were added correctly
    for (int i = 0; i < width * height; i++) {
        if (matrix1[i] != arr[i] * 2 || matrix2[i] != arr[i]) {
            std::cout << "testAdd(): FAILED" << std::endl;
            return;
        }
    }

    // check adding empty/null arrays
    width = 0;
    height = 0;
    int arr2[0];

    MyMatrix<int> matrix3(width, height, arr2);
    MyMatrix<int> matrix4(width, height, arr2);
    try {
        matrix3.Add(matrix4);
    } catch (const std::exception& e) {
        printf("testAdd(): FAILED, could not add empty arrays %s\n", e.what());
		return;
    }

    std::cout << "testAdd(): PASSED" << std::endl;
}

// would be weird to move main to another cpp file, given it only calls one
// function, so I left it in test
int main() {
    testAdd();
}
