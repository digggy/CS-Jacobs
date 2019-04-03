/*
CH08-320142
Problem 3.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <string>
#include "City.h"

using namespace std;

//setter methods

void City::setLocation(string newLocation){
    location = newLocation;
}

void City::setPoi(string newPoi){
    poi = newPoi;
}

void City::setNumOfCitizens(int newNumOfcitizen){
    numOfCitizen = newNumOfcitizen;
}

//getter methods

string City::getName() {return name;};
string City::getLocation(){return location;};
string City::getPoi() {return poi;};
int City::getNumOfCitizens(){return numOfCitizen;};

//print details method
void City::print(){
    cout<<"----------------------------"<<endl;
    cout << "The City      : "<< getName()<<endl;
    cout << "City Location : "<< getLocation()<<endl;
    cout << "Polulation    : "<< getNumOfCitizens()<<endl;
    cout << "Destinations  : "<< getPoi()<<endl;
    cout<<"----------------------------"<<endl; 
}
