CC = g++
CFLAGS = -Wall

all: compile

compile: Queue.h testqueue.cpp
	$(CC) $(CFLAGS) -o queue Queue.h testqueue.cpp 
run:
	./queue
clean:
	rm -f queue 