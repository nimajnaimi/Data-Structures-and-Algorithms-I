#ifndef MYMATRIX_H
#define MYMATRIX_H

// This class creates a 2 dimensional matrix. The user is able to get the height
// and width of the matrix, add matrices, and print the contents of the matrix.
template<class T>
class MyMatrix{
private:
    int width; // the number of columns the matrix has
    int height; // the number of rows the matrix has
    T* matrix;

public:
    MyMatrix() = delete;

    // default constructor
    MyMatrix(int width, int height, T* matrix) : width(width), height(height) {
        this->matrix = new T[width * height];
        for (int i = 0; i < width * height; i++) {
            this->matrix[i] = matrix[i];
        }
    }

    // adds the contents of another matrix to this matrix
    void Add(MyMatrix & theOtherMatrix) {
        if (width != theOtherMatrix.width || height != theOtherMatrix.height) {
            std::cout << "Matrix addition FAILED: Must use matrices with the same dimensions" << std::endl;
            return;
        }

        for (int i = 0; i < width * height; i++) {
            matrix[i] = matrix[i] + theOtherMatrix[i];
        }
    }

    // prints the contents of the matrix
    void Print() {
        for (int i = 1; i <= height; i++) {
            for (int j = width * (i - 1); j < width * i; j++) {
                std::cout <<  matrix[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    T& operator[](int index) {
        return matrix[index];
    }

    // destructor
    virtual ~MyMatrix() {
        delete[] matrix;
    }
};

#endif // MYMATRIX_H
