/*
CH08-320142
Problem 3.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <string> // defines standard C++ string class

class Critter
{
private:  // data members are private
	std::string name;
	double hunger; // setting the hunger to double
	int boredom;
	double height;
	double thirst;

	//new method to change the hungerlevel 
	double cHunger(int hunger);
	int cHunger();
	
public: 
	
	//constructors 
	Critter();
	Critter(std::string name);
    Critter(std::string name ,int hunger,int boredom,double height=15);
	Critter(std::string name,int hunger,int boredom,double height,double thirst);
	
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setThirst(double thirst);

	// getter method
	int getHunger();
	double getThirst();
	
	// service method
	void print();
};
