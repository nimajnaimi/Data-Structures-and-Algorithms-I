#include "circular_card.h"

template<class T>
bool circular_card<T>::operator<(circular_card<T> const &cir) {
    return area() < cir.area();
}
