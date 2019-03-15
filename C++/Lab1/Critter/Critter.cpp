/*
CH08-320142
Problem 2.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

//using namespace std;

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::print() {
	std::cout << "I am " << name << ". My hunger level is " << hunger << "." << std::endl;
}

int Critter::getHunger() {
	return hunger;
}