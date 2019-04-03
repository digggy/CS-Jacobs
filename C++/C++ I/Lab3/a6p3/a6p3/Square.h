/*
CH08-320142
Problem 6.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#ifndef _SQUARE_H
#define _SQUARE_H
#include"Rectangle.h"

class Square : public Rectangle {
	public:
		Square(const char *n, double a);
		~Square();
	private:
		double length;
};

#endif
