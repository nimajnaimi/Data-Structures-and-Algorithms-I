#pragma once

#include "card.h"

#define PI 3.14159

template<class T>
class circular_card : public card<T> {
private:
    T m_radius;
public:

    circular_card() = delete;

    explicit circular_card(T radius) : m_radius(radius) {};

    T area() const override {
        return PI * m_radius * m_radius;
    }

    T perimeter() const override {
        return PI * 2 * m_radius;
    }

    bool operator<(circular_card const &);
};
