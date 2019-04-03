/*
CH08-320142
Problem 2.6cpp
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
	
	// setter methods
	void setName(std::string& newname) {
	name = newname;
	}
	void setHunger(int newhunger);
	void setBoredom(int newboredom);

	// getter method
	int getHunger();
	
	// service method
	void print();
};
