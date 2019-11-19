#include "SortedSingleLinkedList.h"

template <class T>
void SortedSingleLinkedList<T>::insert(T val){
    ListNode<T> *ptr = head;
    ListNode<T> *ptr2 = nullptr;
    ListNode<T> *ptrNew = new ListNode(val); // node to be inserted
    // find where to insert the node
    while (ptr->next != nullptr && ptr->next->val < val) {
        ptr = ptr->next;
    }
    ptr2 = ptr->next;
    ptr->next = ptrNew;
    ptrNew->next = ptr2;
}

template <class T>
int SortedSingleLinkedList<T>::size() const {
    T count = 0;
    ListNode<T> *ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
        count++;
    }

    return count;
}

/*
 * delete everything from the linked list
 */
template <class T>
void SortedSingleLinkedList<T>::clear() {
    ListNode<T>* ptr = head->next;
    while (ptr != nullptr) {
        ListNode<T>* curr = ptr;
        ptr = ptr->next;
        delete curr;
    }
    head->next = nullptr;
}

template <class T>
std::vector<T> SortedSingleLinkedList<T>::toVector() const {
    std::vector<T> output;
    for (ListNode<T> *ptr = head->next; ptr != nullptr; ptr = ptr->next) {
        output.push_back(ptr->val);
    }
    return output;
}

template<class T>
void SortedSingleLinkedList<T>::merge(SortedSingleLinkedList &otherList) {
    // this is the way I would implement the function if calling insert(T val)
    /*
    ListNode<T>* otherPtr = otherList.head->next;
    while (otherPtr != nullptr) {
        insert(otherPtr->val);
        otherPtr = otherPtr->next;
    }
    */

    ListNode<T>* otherPtr = otherList.head->next;
    ListNode<T> *ptr = head;
    ListNode<T> *ptr2 = nullptr;
    while (otherPtr != nullptr) {
        ListNode<T> *ptrNew = new ListNode(otherPtr->val);
        while (ptr->next != nullptr && ptr->next->val < otherPtr->val) {
            ptr = ptr->next;
        }
        ptr2 = ptr->next;
        ptr->next = ptrNew;
        ptrNew->next = ptr2;
        otherPtr = otherPtr->next;
    }
}



