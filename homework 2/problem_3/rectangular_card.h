#pragma once

#include "card.h"

template<class T>
class rectangular_card : public card<T> {
private:
    T m_width, m_height;
public:
    rectangular_card() = delete;

    rectangular_card(T width, T height)
            : m_width(width), m_height(height) {};

    T area() const override { return m_width * m_height; }

    T perimeter() const override { return (2 * m_width) + (2 * m_height); }

    bool operator<(rectangular_card const &rect);
};
