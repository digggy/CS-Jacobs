/*
CH08-320143
a6p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <string>

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction
{
private:
    int denominator, numerator;

public:
    // Constructors
    Fraction();
    Fraction(const int &numerator, const int &denominator);
    Fraction(const Fraction &src);
    Fraction(const std::string &src);
    // Destructor
    ~Fraction();

    /* Logic operators */
    bool operator<(const Fraction &src) const;
    bool operator>(const Fraction &src) const;
    bool operator<=(const Fraction &src) const;
    bool operator>=(const Fraction &src) const;
    bool operator==(const Fraction &src) const;
    bool operator!=(const Fraction &src) const;

    //Assignment operator
    Fraction operator=(const Fraction &src);

    //Overloading the input and output operators
    friend std::ostream &operator<<(std::ostream &out, const Fraction &src);
    friend std::istream &operator>>(std::istream &in, Fraction &inf);

    //Other airthemetic operators
    Fraction operator+(const Fraction &src);
    Fraction operator-(const Fraction &src);
    Fraction operator*(const Fraction &src);
    Fraction operator/(const Fraction &src);
};

#endif