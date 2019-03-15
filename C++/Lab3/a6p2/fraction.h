/*
CH08-320142
Problem 6.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

#include<iostream>

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1
	void print();				// prints it to the screen

	//friend functions 
	friend std::istream& operator>>(std::istream& in, Fraction& term);
	friend std::ostream& operator<<(std::ostream& out,const Fraction& term);;

	//overloaded operators
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator=(Fraction&);

	bool operator>(Fraction);
	bool operator<(Fraction);
	

};


#endif /* FRACTION_H_ */
