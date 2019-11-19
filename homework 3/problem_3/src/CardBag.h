#pragma once

#include "CardBagInterface.h"
#include <list>
#include <iostream>

template <class T>
class CardBag : CardBagInterface<T> {
private:
    std::list<Card<T>*> items;
    int capacity;
public:
    CardBag() = delete;

    ~CardBag() {
        items.clear();
    }

    CardBag(int capacity) : capacity(capacity) {
    };

    int getCount() const override {
        return items.size();
    }

    bool isEmpty() const override {
        return items.empty();
    }

    bool isFull() const override {
        return getCount() == capacity;

        // or the bag is never full
        // return false;
    }

    bool add(Card<T> *item) override {
        bool can_add = !isFull();
        if (can_add) {
            items.push_back(item);
            printf("area: %f\n", item->area());
        }
        return can_add;
    };

    bool remove(Card<T> *item) override {
        bool is_deleted = false;
        for (auto it = items.begin(); it != items.end(); it++) {
            if ((*it) == item) {
                items.erase(it);
                is_deleted = true;
            }
        }
        return is_deleted;
    };

    bool contains(Card<T> *item) override {
        for (auto it = items.begin(); it != items.end(); it++) {
            if (*it == item) {
                return true;
            }
        }
        return false;
    };

    Card<T>* maxArea() override {
        if (items.size() == 0) {
            return nullptr;
        }
        Card<T>* ptr = *items.begin(); // stores the pointer to the card with largest area
        T maxArea = (*items.begin())->area(); // stores the largest area found in the bag
        for (auto it = items.begin(); it != items.end(); it++) {
            if ((*it)->area() > maxArea) {
                maxArea = (*it)->area();
                ptr = *it;
            }
        }
        return ptr;
    }
};
