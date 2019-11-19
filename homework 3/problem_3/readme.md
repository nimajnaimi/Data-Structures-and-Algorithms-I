## Find the largest card in the bag (20pt)

Use folder ```problem_3```.

We all love our card bag examples right? well, here's your chance to contribute to it.

### 1. (10pt) Add a maxArea() function to the CardBag interface and class

The bag can only contain cards of type either CircularCard or RectangularCard.

In fact the maxArea has been added to ***src/CardBagInterface.h***

```C++
    virtual Card<T>* maxArea() = 0;
```

The task is to complete the implementation of maxArea in ***src/CardBag.h***. Skeleton code is already provided:
```C++
    Card<T>* maxArea() override {
        // homework
    }
```

This function will return the pointer to one card in the bag that has the largest area no matter what shape it is (CircularCard or RectangularCard). 

For example, if the bag contains the following cards:

```C++
    FloatRectangularCard r1(1, 2);
    FloatCircularCard c1(3);
    FloatCircularCard c2(4);
```

Then maxArea() should return a pointer to c2 because it has the largest area 50.265442 comparing to 28.274309 and 2.0.

### 2. (10pt) Write a unit test in test/unit_tests.cpp to verify your maxArea()

At least the following cases need to be covered

* Bag is empty (maxArea() should return nullpt)
* Bag contains only CircularCard objects with different area values
* Bag contains only RectangularCard objects with different area values
* Bag contains both RectangularCard and CircularCard objects with different area values
* Bag contains both RectangularCard and CircularCard objects with same area values

