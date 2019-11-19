#pragma once

#include "Card.h"

#define PI 3.14159

template<class T>
class CircularCard : public Card<T> {
private:
    T m_radius;
public:

    CircularCard() = delete;

    explicit CircularCard(T radius) : m_radius(radius) {};

    T area() const override {
        return PI * m_radius * m_radius;
    };
};
