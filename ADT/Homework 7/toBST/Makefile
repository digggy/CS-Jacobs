CC = g++
CFLAGS = -Wall

all: compile

compile: LinkedList.h BST.h toBST.cpp
	$(CC) $(CFLAGS) -o main LinkedList.h BST.h toBST.cpp
run:
	./main
clean:
	rm -f main 