#pragma once

#include "Card.h"

template <class T>
class CardBagInterface {
public:
    virtual int getCount() const = 0;

    virtual bool isEmpty() const = 0;

    virtual bool isFull() const = 0;

    virtual bool add(Card<T>*) = 0;

    virtual bool remove(Card<T>*) = 0;

    virtual bool contains(Card<T>*) = 0;

	// homework
	virtual Card<T>* maxArea() = 0;
};