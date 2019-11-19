FLAGS=-Wall -std=c++11
CC=g++

all: test.x

circular_card.o: circular_card.cpp circular_card.h card.h
	$(CC) $(FLAGS) -c circular_card.cpp -o circular_card.o

rectangular_card.o: rectangular_card.cpp rectangular_card.h card.h
	$(CC) $(FLAGS) -c rectangular_card.cpp -o rectangular_card.o

test.o: test.cpp test.h
	$(CC) $(FLAGS) -c test.cpp  -o test.o

test.x: test.o circular_card.o rectangular_card.o
	$(CC) test.o rectangular_card.o circular_card.o -o test.x

clean:
	rm *.x *.o
