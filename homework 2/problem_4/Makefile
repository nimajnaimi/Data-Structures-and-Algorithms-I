FLAGS=-Wall -std=c++11
CC=g++

all: problem4.x

test.o: test.cpp test.h MyMatrix.h
	$(CC) $(FLAGS) -c test.cpp -o test.o

problem4.x: test.o
	$(CC) test.o -o problem4.x

clean:
	rm *.x *.o
