/*
CH08-320142
Problem 2.7.cpp
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
	std::string color; 
	int lifespan;
	double height;
	  
public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
    void setColor(std::string& newcolor) ;
	void setLifespan(int newlifespan); 
	// getter method
	int getLifespan();
	int getHunger();
	std::string getColor();
	// service method
	void print();
};

