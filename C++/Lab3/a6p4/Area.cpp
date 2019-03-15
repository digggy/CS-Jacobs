/*
CH08-320142
Problem 6.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstring>
#include "Area.h"
using namespace std;

Area::Area(const char* n) {
	strncpy(color, n, 10);
	cout << "Area constructor being called...\n";
}

Area::~Area() {
	cout<<"Area Destructor being called "<<endl;	
	cout<<"Area Destructor being called "<<endl;
	cout<<"Area Destructor being called "<<endl;
	cout<<"Area Destructor being called "<<endl;

}

void Area::getColor() const {
	cout << "\n" << color << ": ";
}
