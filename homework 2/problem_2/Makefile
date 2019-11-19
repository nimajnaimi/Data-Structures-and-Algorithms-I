FLAGS=-Wall -std=c++11
CC=g++

all: homework2.x

base.o: base.cpp base.h
	$(CC) $(FLAGS) -c base.cpp -o base.o

classA.o: classA.cpp classA.h base.cpp base.h
	$(CC) $(FLAGS) -c classA.cpp  -o classA.o

classB.o: classB.cpp classB.h base.cpp base.h
	$(CC) $(FLAGS) -c classB.cpp  -o classB.o

main.o: base.cpp base.h classA.cpp classA.h classB.cpp classB.h
	$(CC) $(FLAGS) -c main.cpp  -o main.o

homework2.x: main.o classB.o classA.o base.o
	$(CC) main.o classB.o classA.o base.o -o homework2.x

clean:
	rm *.x *.o
