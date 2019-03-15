/*
CH08-320142
Problem 3.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"
#include <string>

using namespace std;

//Constructors with no parameter
Critter::Critter() : name("Critter"){
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
    cout<<"Constructor with four parameters Called"<<endl;
    hunger=cHunger(newHunger);
    boredom=newBoredom;
    height=newHeight;

}

//Setters
void Critter::setName(string& newName) {
    name = newName;
    }

void Critter::setHunger(int newhunger) {
	hunger = cHunger(newhunger);
    }   

//Getter
int Critter::getHunger() {
	return cHunger();
    }

//Service Method
void Critter::print() {
    cout<<"__________________________________________"<<endl;
	cout << "I am " << name << endl;
    cout<<"My hunger level is " << getHunger() << "." << endl;
	cout << "I have " << boredom <<" boredom."<< endl;
    cout<<"My height is " << height << "." << endl;
    cout<<"__________________________________________"<<endl;
    }

//converting the int to double
double Critter::cHunger(int hunger){
    return(double)hunger/10;
}

//converting the double to int
int Critter::cHunger(){
    return (int)(hunger*10);
}