CC = g++
CFLAGS = -Wall

all: compile

compile: LinkedList.h BST.h tolist.cpp
	$(CC) $(CFLAGS) -o main LinkedList.h BST.h tolist.cpp
run:
	./main
clean:
	rm -f main 