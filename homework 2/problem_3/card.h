#pragma once

template<class T>
class card {
public:
    virtual T area() const = 0;
    virtual T perimeter() const = 0;
};
