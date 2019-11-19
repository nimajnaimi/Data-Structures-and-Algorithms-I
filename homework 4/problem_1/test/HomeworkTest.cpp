#include "gtest/gtest.h"
#include "Homework.h"
#include "LinkedStack.h"

// reverses the stack and the vector, verifies all elements match, and
// clears all elements in the vector
void checkReverseEqual(Stack<int> &stack, std::vector<int> &vector) {
    reverse_stack_recursively(stack);
    for (int i = 0; i <= vector.size() && !stack.isEmpty(); i++) {
        ASSERT_EQ(stack.peek(), vector[i]);
        stack.pop();
    }
    ASSERT_TRUE(stack.isEmpty());
    vector.clear();
}

TEST(stack_reversal, test) {
    // empty stack
    LinkedStack<int> myStack;
    reverse_stack_recursively(myStack);
    ASSERT_TRUE(myStack.isEmpty());

    // stack with one element
    std::vector<int> myVector;
    myStack.push(0);
    myVector.push_back(0);
    checkReverseEqual(myStack, myVector);

    // stack with two different elements
    myStack.push(0);
    myStack.push(1);
    myVector.push_back(0);
    myVector.push_back(1);
    checkReverseEqual(myStack, myVector);

    // stack with multiple different elements
    for (int i = 0; i < 3; i++) {
        myStack.push(i);
        myVector.push_back(i);
    }
    checkReverseEqual(myStack, myVector);

    // stack with multiple elements and repeated values
    myStack.push(0);
    myStack.push(2);
    myStack.push(2);
    myStack.push(3);
    myVector.push_back(0);
    myVector.push_back(2);
    myVector.push_back(2);
    myVector.push_back(3);
    checkReverseEqual(myStack, myVector);
}
