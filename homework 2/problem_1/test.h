//.....Name: Nima Naimi
//.....Date: October 4th, 2019
//.....Homework #1

#ifndef TEST_H
#define TEST_H

/*
 * test MyArray::add()
 */
void testAdd();

/*
 * test MyArray::sort()
 */
void testSort();

/*
 * test MyArray::reverse()
 */
void testReverse();

// Base class for MyArray. Defines the functions of MyArray.
template<class T>
class Container {
    // return the number of elements in the array
    virtual int count() const = 0;

    // add an element to the end of the array
    virtual void add(T &val) = 0;

    // sort the container elements in ascending order
    // for example:
    // 	input: [3, 1, 4, 5, 4, 2]
    // 	output: [1, 2, 3, 4, 4, 5]
    virtual void sort() = 0;

    // reverse the elements of the array backward
    // examples:
    // 	input: [], output: []
    // 	input: [2], output: [2]
    // 	input: [1, 2, 1], output: [1, 2, 1]
    // 	input: [1, 2, 3, 4, 4, 5], output: [5, 4, 4, 3, 2, 1]
    virtual void reverse() = 0;
};

/*
 * Creates an array of type T. Can sort the array into ascending order,
 * reverse the elements of the array, add elements into the array, and
 * give the current size of the array.
 * Inherits from Container class.
 */
template<class T>
class MyArray: public Container<T> {
    private:
        T * data;
        int capacity;
        int size;

    public:
        // constructor
        MyArray(int capacity) : capacity(capacity), size(0) {
            data = new T[capacity];
        }

        // copy constructor
        MyArray(const MyArray & array) {
            size = array.size;
            capacity = array.capacity;
            data = new T[capacity];
            for (int i = 0; i < array.capacity; i++) {
                data[i] = array.data[i];
            }
        }

        // destructor
        virtual ~MyArray() {
            delete []data;
        }

        // returns the size of the array
        int count() const override {
            return size;
        }

        T & operator [](int index) {
            return data[index];
        }

        // adds the value to the end of the array and updates the size
        void add(T & val) override {
            if (size==capacity) {
                return;
            }

            data[size] = val;
            size++;
        }

        // sorts the elements of the array into ascending order
        void sort() override {
            // sorting algorithm
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (data[i] > data[j]) {
                        T temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
        }

        // reverses the order of the array's elements
        void reverse() override {
            // reversing algorithm
            for (int i = 0; i < size / 2; i++) {
                T temp = data[i];
                data[i] = data[size - (i + 1)];
                data[size - (i + 1)] = temp;
            }
        }
};

#endif // TEST_H
