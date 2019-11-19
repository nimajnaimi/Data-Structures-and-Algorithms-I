#include "SortedSingleLinkedList.h"
#include "gtest/gtest.h"

// homework needs fix
TEST(sll_test, to_vector) {
    SortedSingleLinkedList<int> list;
    int testSize = 5;
    std::vector<int> answer;
    for (int i = 0; i < testSize; i++) {
        answer.push_back(i);
        list.insert(i);
    }

    ASSERT_EQ(list.size(), testSize);
    ASSERT_TRUE(answer == list.toVector());
}

TEST(sll_test, insert) {
    // input is empty
    SortedSingleLinkedList<int> list;
    std::vector<int> answer;
    list.insert(1);
    answer.push_back(1);
    ASSERT_TRUE(answer == list.toVector());

    // input has one element
    list.insert(2);
    answer.push_back(2);
    ASSERT_TRUE(answer == list.toVector());

    //  input has more than one elements without duplicates
    list.insert(0);
    answer.insert(answer.begin(), 0);
    ASSERT_TRUE(answer == list.toVector());

    // input has more than one elements with duplicates
    list.insert(2);
    answer.insert(answer.begin() + 2, 2);
    list.insert(2);
    answer.insert(answer.begin() + 2, 2);
    ASSERT_TRUE(answer == list.toVector());

    // input has more than one elements, all elements being the same values
    list.clear();
    answer.clear();
    for (int i = 0; i < 5; i++) {
        list.insert(3);
        answer.push_back(3);
    }
    ASSERT_TRUE(answer == list.toVector());
}

TEST(sll_test, merge) {
    // homework

    // If current list is empty, and the other list is also empty, after merge the current list will still be empty
    SortedSingleLinkedList<int> currentList;
    SortedSingleLinkedList<int> otherList;
    std::vector<int> answer;
    currentList.merge(otherList);
    ASSERT_TRUE(answer == currentList.toVector());

    // If the current list is 1->3, and the other list is 2->4, after merge the current list will be 1->2->3->4
    currentList.insert(1);
    currentList.insert(3);
    otherList.insert(2);
    otherList.insert(4);
    currentList.merge(otherList);
    for (int i = 1; i <= 4; i++) {
        answer.push_back(i);
    }
    ASSERT_TRUE(answer == currentList.toVector());

    //  If the current list is 1->3, and the other list is 4->5, after merge the current list will be 1->3->4->5
    currentList.clear();
    otherList.clear();
    answer.clear();
    currentList.insert(1);
    currentList.insert(3);
    otherList.insert(4);
    otherList.insert(5);
    currentList.merge(otherList);
    for (int i = 1; i <= 5; i++) {
        if (i != 2) {
            answer.push_back(i);
        }
    }
    ASSERT_TRUE(answer == currentList.toVector());

    // If the current list is 6->7->8, and the other list is 4->5, after merge the current list will be 4->5->6->7->8
    currentList.clear();
    otherList.clear();
    answer.clear();

    for (int i = 6; i <= 8; i++) {
        currentList.insert(i);
        answer.push_back(i);
    }

    otherList.insert(4);
    otherList.insert(5);
    answer.push_back(4);
    answer.push_back(5);

    sort(answer.begin(), answer.end());
    currentList.merge(otherList);
    ASSERT_TRUE(answer == currentList.toVector());

    // If the current list is 3->3->8, and the other list is 2->5, after merge the current list will be 2->3->3->5->8
    currentList.clear();
    otherList.clear();
    answer.clear();

    currentList.insert(3);
    currentList.insert(3);
    currentList.insert(8);
    answer.push_back(3);
    answer.push_back(3);
    answer.push_back(8);

    otherList.insert(2);
    otherList.insert(5);
    answer.push_back(2);
    answer.push_back(5);

    sort(answer.begin(), answer.end());
    currentList.merge(otherList);
    ASSERT_TRUE(answer == currentList.toVector());
}
