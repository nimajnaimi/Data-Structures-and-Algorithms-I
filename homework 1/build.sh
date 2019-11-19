#!/bin/bash

# print out each command being executed 
set -x

rm homework1.x 

g++ -c homework1.cpp -Wall -std=c++11 -o homework1.o
g++ -c test.cpp -Wall -std=c++11 -o test.o
g++ homework1.o test.o -o homework1.x
