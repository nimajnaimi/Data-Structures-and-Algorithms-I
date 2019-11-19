#include "Stack.h"

// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
void insertBottomOfStack(Stack<int> &stack, int num) {
    if (stack.isEmpty()) {
        stack.push(num);
        return;
    }
    int temp = stack.peek(); // stores the values in a "third stack" (values are in order)
    stack.pop();
    insertBottomOfStack(stack, num);
    stack.push(temp); // pushes the values back to the original stack (values are reversed)
}

void reverse_stack_recursively(Stack<int> &stack) {
    if (!stack.isEmpty()) {
        int temp = stack.peek(); // stores the values in a "second stack" (values are reversed)
        stack.pop();
        reverse_stack_recursively(stack);
        insertBottomOfStack(stack, temp); // called when the stack becomes empty
    }
}
