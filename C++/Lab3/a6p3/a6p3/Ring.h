/*
CH08-320142
Problem 6.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _RING_H
#define _RING_H
#include "Circle.h"

class Ring : public Circle {
	public:
		Ring(const char *n, double outer, double inner);
		~Ring();
		double calcArea() const;
		double calcPerimeter() const;
	private:
		double innerradius;
};

#endif
