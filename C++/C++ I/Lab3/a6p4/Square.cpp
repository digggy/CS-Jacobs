/*
CH08-320142
Problem 6.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Square.h"

Square::Square(const char *n, double a) : Rectangle(n,a,a) {
    length = a;
}

Square::~Square() {
}
