/*
CH08-320142
Problem 3.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	//Creating Critter Objects 
    Critter ankit;
	ankit.setHunger(5); //setting Ankit's Hunger

	Critter dipak("Dipak");
	dipak.setHunger(5); //setting dipak's Hunger
	
	Critter subarna("Subarna",5,4);
	Critter aman("Aman",5,71,7059);

	//printing out the values stored in properties
	ankit.print();
	dipak.print();
	subarna.print();
	aman.print();
	
    return 0;
}
