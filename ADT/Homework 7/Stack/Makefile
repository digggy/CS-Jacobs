CC = g++
CFLAGS = -Wall

all: compile

compile: Stack.h teststack.cpp
	$(CC) $(CFLAGS) -o stack Stack.h teststack.cpp 
run:
	./stack
clean:
	rm -f stack 