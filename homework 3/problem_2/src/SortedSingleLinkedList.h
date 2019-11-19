#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_

#include "ListNode.h"
#include <vector>

template <class T>
class SortedSingleLinkedList {
private:
    ListNode<T> *head;
public:
    SortedSingleLinkedList() {
        head = new ListNode<T>();
    }

    ~SortedSingleLinkedList() {
        clear();
        delete head;
    }

    std::vector<T> toVector() const;
    void clear();
    int size() const;

    void insert(T);
    void merge(SortedSingleLinkedList &);
};

#include "SortedSingleLinkedList.cpp"

#endif
