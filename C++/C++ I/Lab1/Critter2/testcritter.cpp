/*
CH08-320142
Problem 2.7.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	string name;
	int hunger;
    int lifespan;
	string color;

	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
    cout<<"Lifespan:";
	cin.get();
	cin>>lifespan; getchar();
	c.setLifespan(lifespan);
    cout<<"Color:";
	getline(cin,color);
	c.setColor(color);
	cout << "You have created:" << endl;
	c.print();
    return 0;
}
