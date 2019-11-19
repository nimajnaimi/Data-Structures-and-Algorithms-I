#include "gtest/gtest.h"

#include "possible_paths.h"

TEST(test_recursive, zero) {
    ASSERT_EQ(possiblePathsRecursive(0, 0), 0);
    ASSERT_EQ(possiblePathsRecursive(0, 1), 0);
    ASSERT_EQ(possiblePathsRecursive(0, 1), 0);
}

TEST(test_recursive, one) {
    ASSERT_EQ(possiblePathsRecursive(1, 1), 1);
    ASSERT_EQ(possiblePathsRecursive(1, 2), 1);
    ASSERT_EQ(possiblePathsRecursive(2, 1), 1);
}

TEST(test_recursive, demo) {
    ASSERT_EQ(possiblePathsRecursive(3, 2), 3);
    ASSERT_EQ(possiblePathsRecursive(7, 3), 28);
    ASSERT_EQ(possiblePathsRecursive(2, 4), 4);

    ASSERT_EQ(possiblePathsRecursive(2, 5), 5);
    ASSERT_EQ(possiblePathsRecursive(3, 4), 10);
    ASSERT_EQ(possiblePathsRecursive(3, 5), 15);
}

TEST(test_iterative, zero) {
    ASSERT_EQ(possiblePathsIterative(0, 0), 0);
    ASSERT_EQ(possiblePathsIterative(0, 1), 0);
    ASSERT_EQ(possiblePathsIterative(0, 1), 0);
}

TEST(test_iterative, one) {
    ASSERT_EQ(possiblePathsIterative(1, 1), 1);
    ASSERT_EQ(possiblePathsIterative(1, 2), 1);
    ASSERT_EQ(possiblePathsIterative(2, 1), 1);
}

TEST(test_iterative, demo) {
    ASSERT_EQ(possiblePathsIterative(3, 2), 3);
    ASSERT_EQ(possiblePathsIterative(7, 3), 28);
    ASSERT_EQ(possiblePathsIterative(2, 4), 4);

    ASSERT_EQ(possiblePathsIterative(2, 5), 5);
    ASSERT_EQ(possiblePathsIterative(3, 4), 10);
    ASSERT_EQ(possiblePathsIterative(3, 5), 15);
}

