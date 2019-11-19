FLAGS=-Wall -std=c++11
CC=g++

all: homework1.x

homework1.o: homework1.cpp
	$(CC) $(FLAGS) -c homework1.cpp -o homework1.o

test.o: test.cpp test.h
	$(CC) $(FLAGS) -c test.cpp  -o test.o

homework1.x: test.o homework1.o
	$(CC) test.o homework1.o -o homework1.x

clean:
	rm *.x *.o
