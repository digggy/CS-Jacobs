CC      = g++
FLAGS  = -Wall

all:		arithmetic relational Oop exception
			./arithmetic 
			./relational  
			./exception
			./Oop
			
test-arithmetic:		arithmetic
			./arithmetic

test-relational:		relational
			./relational

test-IO:		Oop
			./Oop

test-exception:		exception
			./exception

arithmetic:	Fraction.o
			$(CC) Fraction.o -o arithmetic testarithmeticop.cpp

relational:	Fraction.o
			$(CC) Fraction.o -o relational testrelationalop.cpp

Oop:	Fraction.o
			$(CC) Fraction.o -o Oop testOop.cpp 

exception:	Fraction.o
			$(CC) Fraction.o -o exception testexceptions.cpp

Fraction.o:		Fraction.cpp Fraction.h
			$(CC) $(FLAGS) -c Fraction.cpp 
remove:		
			rm -f *.o 