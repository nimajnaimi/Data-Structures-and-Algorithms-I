#include "rectangular_card.h"

template<class T>
bool rectangular_card<T>::operator<(rectangular_card<T> const &rect) {
    return area() < rect.area();
}

