* Info:
    - Assigned: 09/26/2019
    - Due: **10/4/2019 Friday 11:59pm**
    - Submission via Canvas
    - Your code will be graded on my Ubuntu Linux.  **Before** submitting your work, make sure your code works on this platform especially if you code on another platform like Windows. Simple rule of judgement: If *build.sh* does not produce an executable called *homework1.x*, it **DOESN'T** compile for this homework. In future homework, you will loose most of the points if your code does not compile. 
    - Your work will be graded as following:
        - compiles (10 pt): produces a binary executable called homework1.x 
        - correct (10 pt): pass all tests, sufficient test cases
        - style (5 pt): naming convension, clear comments, etc.
        - bonus (10 pt): Graded following the previous 3 standards
    

* Check out the project using git tool. 

```bash
git clone https://github.com/pdgetrf/UWB_CSS342_2019_Fall.git
```

Here's what it looks like on Ubuntu Linux:

```console
pdu@pdu-VirtualBox:~/teaching$ git clone https://github.com/pdgetrf/UWB_CSS342_2019_Fall.git
Cloning into 'UWB_CSS342_2019_Fall'...
remote: Enumerating objects: 89, done.
remote: Counting objects: 100% (89/89), done.
remote: Compressing objects: 100% (78/78), done.
remote: Total 89 (delta 21), reused 47 (delta 6), pack-reused 0
Unpacking objects: 100% (89/89), done.

pdu@pdu-VirtualBox:~/teaching$ ls
UWB_CSS342_2019_Fall
pdu@pdu-VirtualBox:~/teaching$ cd UWB_CSS342_2019_Fall/class1/homework/
```

The homework is in **UWB_CSS342_2019_Fall/class1/homework/**. 

* Finish the following tasks:

1. (25pt) Separate all tests into a separate file called **test.cpp**, this file should include the following functions:

```cpp
void testReverse();
void testSort();
void testAdd();
```


Modify *build.sh* to include **test.cpp**, and *build.sh* should still compile the project correctly.

2. (25pt) Complete the **add()** and **testAdd()**
```cpp
    // add an element to the end of the array
    virtual void add(T &val) = 0;
```

*add()* is already partially implemented from class. Finish this task based on what's already written.

3. (25pt) Implement **sort()** and **testSort()**
```cpp
    // sort the container elements in ascending order
    // for example:
    //  input: [3, 1, 4, 5, 4, 2]
    //  output: [1, 2, 3, 4, 4, 5]
    virtual void sort() = 0;
```
Any method to sort an array can be used, even bubble sort. You will **NOT** be scored based on algorithm performance, only on correctness. Write tests as thourough as possible. Result must be *in-place* as in taking effect on the same array object from test input.

 
4. (25pt) Implement **reverse()** and **testReverse()**
```cpp
    // reverse the elements of the array backward
    // examples:
    //  input: [], output: []
    //  input: [2], output: [2]
    //  input: [1, 2, 1], output: [1, 2, 1]
    //  input: [1, 2, 3, 4, 4, 5], output: [5, 4, 4, 3, 2, 1]
    virtual void reverse() = 0;
```
Any method to reverse an array can be used. You will **NOT** be scored based on algorithm performance, only on correctness. Write tests as thourough as possible. Result must be *in-place* as in taking effect on the same object.

5. (10pt) Bonus: Implement **reverse()** without additional memory space of the same array size. This means *reverse()* work in-place and does not allocate (*new* or *malloc*) another array of the same size when working.
