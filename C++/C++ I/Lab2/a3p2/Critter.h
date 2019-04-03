/*
CH08-320142
Problem 3.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

public: // business logic methods are public
	
	//constructors 
	Critter();
	Critter(std::string name);
    Critter(std::string name,int hunger,int boredom,double height=15);
	
	//setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	
	// getter method
	int getHunger();
	
	// service method
	void print();
};
