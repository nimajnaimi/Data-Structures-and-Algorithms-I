## Complete the Singly Linked List (50pt)

Use folder ```problem_1```.

### 1. (10pt) Implement remove(T val) in ***src/SingleLinkedList.cpp***
```C++
/*
 * Removes all the nodes whose val equals the val in the parameter
 * Return true is any node was actually removed. False otherwise
 */
template <class T>
bool SingleLinkedList<T>::remove(T val) {
    // homework
    return false; // place holder. change this in your homework
}
```
The skeleton code is already provided and should not be modified. 

The remove(T val) will remove all the nodes whose val equals the val in the parameter. Removed nodes are deleted in memory.

For example:
* If the list has 1->2->3, after calling the remove(3) the list will be 1->2, and return true
* If the list has 1->2->4->2, after calling the remove(2) the list will be 1->4, and return true
* If the list has 1->1->4->2, after calling the remove(2) the list will be 4->2, and return true
* If the list has 1->1->4->2, after calling the remove(5) the list will be 1->1->4->2, and return false
* If the list is empty, after calling the remove(2) the list will be empty, and return false
* If the list has 1->1, after calling the remove(1) the list will be empty, and return true


### 2. (10pt) Write a unit test in ***test/unit_tests.cpp*** for your remove(T val) in task 1 to verify it works correctly. The following cases have to be verified in your tests:

* input is empty
* input has one element
* input has more than one elements without duplicates
* input has more than one elements with duplicates
* input has more than one elements, all elements being the same values

Your tests should verify both the correct elements are removed AND remove(T val) returns the correct boolean value. The skeleton code is provided:

```C++
TEST(sll_test, remove) {
    // homework

}
```

hint: ***TEST(sll_test, append)*** provided an exmaple how you can generate testing input, initialize a list object, call the function and compare result.

### 3. (10pt) Implement the copy constructor in ***src/SingleLinkedList.cpp***
```C++
template <class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList &list) {
    // homework 
}
```
This copy constructor does deep-copies. **Assume T could only be int, float or double.**


### 4. (10pt) Add a unit test in ***test/unit_tests.cpp*** to verify the copy constructor you added from task 3 is correct. The following cases have to be verified in your tests:

* input list is empty
* input list has 1 node
* input list has more than 1 nodes

Your tests should verify correct number of nodes have been copied and each node has correct value. The skeleton code is provided

```C++
TEST(sll_test, constructor) {
    // homework

}
```

### 5. (10pt) Implement the linked list reversal in ***test/unit_tests.cpp***
```C++
template <class T>
void SingleLinkedList<T>::reverse_iterative() {
    // homework 
}
```

reverse_iterative() reverse the order of node (**not just the value**) in a linked list. For example:

* If the list is empty, after calling the reverse_iterative() the list will still be empty
* If the list has 1, after calling the reverse_iterative() the list will be 1
* If the list has 1->2->3, after calling the reverse_iterative() the list will be 3->2->1
* If the list has 1->2->3->4, after calling the reverse_iterative() the list will be 4->3->2->1

reverse_iterative() works "in-place" which means no new node should be created during the process. 

The unit test for your reverse_iterative() is already provided in ***src/unit_tests.cpp***
```C++
TEST(sll_test, reverse_iterative) {
    ASSERT_TRUE(test_reverse_iterative_n(0));
    ASSERT_TRUE(test_reverse_iterative_n(1));
    ASSERT_TRUE(test_reverse_iterative_n(2));
    ASSERT_TRUE(test_reverse_iterative_n(3));
    ASSERT_TRUE(test_reverse_iterative_n(4));
}
```

Your reverse_iterative() should pass all of these test cases.


