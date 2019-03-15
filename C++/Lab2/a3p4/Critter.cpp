/*
CH08-320142
Problem 3.4.cpp
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
    thirst=0;
}

//Constructors with one parameter
Critter::Critter(string newName) : name(newName){
    cout<<"Constructor with one parameter Called"<<endl;
    hunger=0;
    boredom=0;
    height=10;
    thirst=0;
}

//Constructors with four parameters
Critter::Critter(string newName,int newHunger,int newBoredom,double newHeight) : name(newName){ 
    cout<<"Constructor with four parameters Called"<<endl;
    hunger=cHunger(newHunger);
    boredom=newBoredom;
    height=newHeight;
    thirst=newHunger;
}
//Constructor with all parameters
Critter::Critter(std::string newName,int newHunger,int newBoredom,double newHeight,double newThirst)
: name(newName){
    cout<<"Constructor with five parameters Called"<<endl;
    hunger=cHunger(newHunger);
    boredom=newBoredom;
    height=newHeight;
    thirst=newThirst;
}

//setter implementation 
void Critter::setName(string& newName) {
    name = newName;
    }

void Critter::setHunger(int newhunger) {
	hunger = cHunger(newhunger);
    }   
void Critter::setBoredom(int newBoredom){
    boredom = newBoredom;
}
void Critter::setThirst(double newThirst){
    boredom = newThirst;
} 
//getter implementation

int Critter::getHunger() {
	return cHunger();
    }
double Critter::getThirst(){
    return thirst;
}

void Critter::print() {
    cout<<"__________________________________________________"<<endl;
	cout << "I am " << name << endl;
    cout<<"My hunger level is " << getHunger() << "." << endl;
	cout << "I have " << boredom <<" boredom."<< endl;
    cout<<"My height is " << height << "." << endl;
    cout<<"My thirst  level is "<<thirst<<endl;
    cout<<"__________________________________________________"<<endl;
    }

//converting the int to double
double Critter::cHunger(int hunger){
    return(double)hunger/10;
}

//converting the double to int
int Critter::cHunger(){
    return (int)(hunger*10);
}