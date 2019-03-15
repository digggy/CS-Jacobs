/*
CH08-320142
Problem 2.7.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"
using namespace std;

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setColor(string& newcolor){
        color=newcolor;
}
void Critter::setLifespan(int newlifespan){
        lifespan=newlifespan;
}
void Critter::print() {
        cout << "I am " << name<< "."<<endl<< "My hunger level is " << hunger << "." << endl;
	cout << "My color is "<<color<<"."<<endl<<"My lifespan is "<<lifespan<<"."<<endl;
}

int Critter::getHunger() {
	return hunger;
}

int Critter::getLifespan(){
        return lifespan;
}

string Critter::getColor(){
    return color;
}
