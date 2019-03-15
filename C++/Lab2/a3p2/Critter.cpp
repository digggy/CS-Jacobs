/*
CH08-320142
Problem 3.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"
#include <string>

using namespace std;

//Constructors with no parameter
Critter::Critter() : name("critter"){
    cout<<"Empty Constructor Called"<<endl;
    hunger=0;
    boredom=0;
    height=10;

}

//Constructors with one parameter
Critter::Critter(string newName) : name(newName){
    cout<<"Constructor with one parameter Called"<<endl;
    hunger=0;
    boredom=0;
    height=10;
}

//Constructors with all parameters
Critter::Critter(string newName,int newHunger,int newBoredom,double newHeight) : name(newName){ 
    cout<<"Constructor with four parameter Called"<<endl;
    hunger=newHunger;
    boredom=newBoredom;
    height=newHeight;

}
//Implementation of setters
void Critter::setName(string& newName) {
    name = newName;
    }

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
    }

void Critter::setBoredom(int newBoredom){
    boredom = newBoredom;
}
//Implementations of getter
int Critter::getHunger() {
	return hunger;
    }
//service methods implementation 
void Critter::print() {
    cout<<"________________________________________"<<endl<<endl;
	cout << "I am " << name <<endl;
    cout<<"My hunger level is " << hunger << "." << endl;
	cout <<"I have " << boredom <<" boredom."<< endl;
    cout<<"My height is " << height << "." << endl;
    cout<<"_________________________________________"<<endl;
    }


