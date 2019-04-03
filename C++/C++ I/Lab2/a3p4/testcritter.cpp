/*
CH08-320142
Problem 3.4.cpp
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
	
	Critter subarna("Subarna",5,7130);
	Critter aman("Aman",5,71,7059);

	Critter amish("Amish",5,6,22,7141);
	Critter satish("Satish",5,6,22,7156);

	//printing out the values stored in properties
	ankit.print();
	dipak.print();
	subarna.print();
	aman.print();
	amish.print();
	satish.print();
    
    return 0;
}
