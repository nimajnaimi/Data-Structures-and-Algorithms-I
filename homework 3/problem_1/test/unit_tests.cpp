#include "SingleLinkedList.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(sll_test, to_vector) {
    SingleLinkedList<int> list;
    int testSize = 5;
    std::vector<int> answer;
    for (int i = 0; i < testSize; i++) {
        answer.push_back(i);
        list.append(i);
    }

    ASSERT_EQ(list.size(), testSize);

    ASSERT_TRUE(answer == list.toVector());
}

TEST(sll_test, clear) {
    // NOT IMPLEMENTED
}

TEST(sll_test, append) {
    SingleLinkedList<int> list;

    int testSize = 5;
    std::vector<int> answer;
    for (int i=0; i<testSize; i++) {
        list.append(i);
        answer.push_back(i);
    }
    ASSERT_TRUE(answer == list.toVector());
}

TEST(sll_test, prepend) {
    SingleLinkedList<int> list;

    int testSize = 5;
    std::vector<int> answer;
    for (int i=0; i<testSize; i++) {
        list.prepend(i);
        answer.insert(answer.begin(), i);
    }
    ASSERT_TRUE(answer == list.toVector());
}


TEST(sll_test, pophead) {
    SingleLinkedList<int> list;
    ASSERT_NO_FATAL_FAILURE(list.popHead());
    ASSERT_EQ(list.size(), 0);

    list.prepend(1);
    list.popHead();
    ASSERT_EQ(list.size(), 0);

    int testSize = 5;
    std::vector<int> answer;
    for (int i = 0; i < testSize; i++) {
        list.append(i);
        if (i!=0) {
            answer.push_back(i);
        }
    }

    list.popHead();
    ASSERT_EQ(list.size(), testSize-1);
    ASSERT_TRUE(answer == list.toVector());
}

TEST(sll_test, poptail) {
    SingleLinkedList<int> list;
    ASSERT_NO_FATAL_FAILURE(list.popTail());
    ASSERT_EQ(list.size(), 0);

    list.prepend(1);
    list.popTail();
    ASSERT_EQ(list.size(), 0);

    int testSize = 5;
    std::vector<int> answer;
    for (int i = 0; i < testSize; i++) {
        list.append(i);
        if (i!=testSize-1) {
            answer.push_back(i);
        }
    }

    list.popTail();
    ASSERT_EQ(list.size(), testSize-1);
    ASSERT_TRUE(answer== list.toVector());
}

TEST(sll_test, remove) {
    // homework

    // input is empty
    SingleLinkedList<int> list;
    ASSERT_FALSE(list.remove(5));

    // input has one element
    list.prepend(4);
    ASSERT_TRUE(list.remove(4));
    ASSERT_EQ(list.size(), 0);

    // input has more than one element without duplicates
    int testSize = 5;
    std::vector<int> answer;
    for (int i = 0; i < testSize; i++) {
        list.append(i);
        if (i != 1) {
            answer.push_back(i);
        }
    }
    ASSERT_TRUE(list.remove(1));
    ASSERT_EQ(list.size(), testSize - 1);
    ASSERT_TRUE(answer == list.toVector());

    // input has more than one element with duplicates
    list.append(3);
    ASSERT_TRUE(list.remove(3));
    answer.erase(std::remove(answer.begin(), answer.end(), 3), answer.end());
    ASSERT_EQ(list.size(), testSize - 2);
    ASSERT_TRUE(answer == list.toVector());

    // input has more than one element, all elements being the same values
    answer.clear();
    list.clear();
    for (int i = 0; i < testSize; i++) {
        list.append(9);
    }
    ASSERT_TRUE(list.remove(9));
    ASSERT_TRUE(answer == list.toVector());
    ASSERT_EQ(list.size(), 0);
}

TEST(sll_test, constructor) {
    // homework
    // copy empty list
    SingleLinkedList<int> list;
    SingleLinkedList<int> listEmpty(list);
    ASSERT_TRUE(list.equal(listEmpty));

    // copy list with one node
    list.append(1);
    SingleLinkedList<int> listOneNode(list);
    ASSERT_TRUE(list.equal(listOneNode));

    // copy list with multiple nodes
    list.append(2);
    list.append(3);
    list.append(4);
    SingleLinkedList<int> listMultiNode(list);
    ASSERT_TRUE(list.equal(listMultiNode));
}

TEST(sll_test, test_equal) {
    int testSize = 5;
    SingleLinkedList<int> list1;
    SingleLinkedList<int> list2;

    ASSERT_TRUE(list1.equal(list2));

    list1.append(1);
    ASSERT_FALSE(list1.equal(list2));

    std::vector input = std::vector<int>{1, 2, 3};
    for (int i=0; i<input.size(); i++) {
        list2.append(input[i]);
    }
    ASSERT_FALSE(list1.equal(list2));

    list1.append(2);
    list1.append(3);
    ASSERT_TRUE(list1.equal(list2));
}

bool test_reverse_iterative_n(int n) {
    SingleLinkedList<int> list;
    for (int i = 0; i < n; i++) {
        list.append(i);
    }

    SingleLinkedList<int> revList;
    for (int i = n - 1; i >= 0; i--) {
        revList.append(i);
    }

    list.reverse_iterative();

    return list.equal(revList);
}

TEST(sll_test, reverse_iterative) {
    ASSERT_TRUE(test_reverse_iterative_n(0));
    ASSERT_TRUE(test_reverse_iterative_n(1));
    ASSERT_TRUE(test_reverse_iterative_n(2));
    ASSERT_TRUE(test_reverse_iterative_n(3));
    ASSERT_TRUE(test_reverse_iterative_n(4));
}

TEST(sll_test, iterator_begin_end_demo) {

    SingleLinkedList<int> list;
    std::vector input = std::vector<int>{4, 3, 4, 4, 5, 4, 4};
    for (int i = 0; i < input.size(); i++) {
        list.append(input[i]);
    }

    int i=0;
    for (SingleLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++ ) {
        ASSERT_EQ(*it, input[i]);
        i++;
    }
}
