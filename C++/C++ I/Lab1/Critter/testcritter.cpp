/*
CH08-320142
Problem 2.6cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"
//using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	std::string name;
	int hunger;
 
	std::cout << std::endl << "Please enter data: " << std::endl;
	std::cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(std::cin, name);
	c.setName(name);
	c.setName(name);
	std::cout << "Hunger: ";
	std::cin >> hunger;
	c.setHunger(hunger);

	std::cout << "You have created:" << std::endl;
	c.print();
        return 0;
}
