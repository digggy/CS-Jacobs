CC = g++
CFLAGS = -Wall

all: compile

compile: OMP.cpp Node.h
	$(CC) $(CFLAGS) -o OMP OMP.cpp 
run:
	./OMP
clean:
	rm -f OMP 