/*
CH08-320143
a6p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "Fraction.h"
#include <exception>
#include <algorithm>
#include <iostream>

using namespace std;

Fraction::Fraction(){};

// Costructor based on parameter
Fraction::Fraction(const int &numerator, const int &denominator)
{
    if (denominator == 0)
    {
        throw "Invalid data or logical error";
    }
    int GreatestCD = __gcd(abs(numerator), abs(denominator));

    this->numerator = numerator / GreatestCD;
    this->denominator = denominator / GreatestCD;

    if (this->numerator < 0 && this->denominator < 0)
    {
        this->numerator = abs(this->numerator);
        this->denominator = abs(this->denominator);
    }
    else if (this->numerator < 0 || this->denominator < 0)
    {
        this->numerator = -abs(this->numerator);
        this->denominator = abs(this->denominator);
    }
};

// Copy Constructor

Fraction::Fraction(const Fraction &src)
{
    this->numerator = src.numerator;
    this->denominator = src.denominator;
};

// Costructor based on string input
Fraction::Fraction(const std::string &src)
{
    if (src.length() == 0)
    {
        throw "Invalid data or logical error";
    }
    size_t found = src.find('/');
    if (found == string::npos)
    {
        throw "Invalid data or logical error";
    }
    else
    {

        string num = src.substr(0, found);
        string denom = src.substr(found + 1);

        try
        {
            int numerator = stoi(num);
            int denominator = stoi(denom);

            if (denominator == 0)
            {
                throw "Invalid data or logical error";
            }

            this->numerator = numerator;
            this->denominator = denominator;
        }
        catch (exception &e)
        {
            throw "Invalid data or logical error";
        }
    }
};
// Destructor
Fraction::~Fraction(){

};

/* Logic operators */

// Operator <
bool Fraction::operator<(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator < src.numerator;
    }
    else
    {
        return this->numerator * src.denominator < this->denominator * src.numerator;
    }
};

// Operator >
bool Fraction::operator>(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator > src.numerator;
    }
    else
    {
        return this->numerator * src.denominator > this->denominator * src.numerator;
    }
};

// Operator <=
bool Fraction::operator<=(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator <= src.numerator;
    }
    else
    {
        return this->numerator * src.denominator <= this->denominator * src.numerator;
    }
};

// Operator >=
bool Fraction::operator>=(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator >= src.numerator;
    }
    else
    {
        return this->numerator * src.denominator >= this->denominator * src.numerator;
    }
};

// Operator ==
bool Fraction::operator==(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator == src.numerator;
    }
    else
    {
        return this->numerator * src.denominator == this->denominator * src.numerator;
    }
};

// Operator !=
bool Fraction::operator!=(const Fraction &src) const
{
    if (this->denominator == src.denominator)
    {
        return this->numerator != src.numerator;
    }
    else
    {
        return this->numerator * src.denominator != this->denominator * src.numerator;
    }
};

//Assignment operator
Fraction Fraction::operator=(const Fraction &src)
{
    return Fraction(src);
};

//Overloading the input and output operators

std::ostream &operator<<(std::ostream &out, const Fraction &src)
{
    if (src.numerator == 0)
    {
        out << 0 << endl;
    }
    else
    {
        out << src.numerator << "/" << src.denominator << endl;
    }
    return out;
};

std::istream &operator>>(std::istream &in, Fraction &inf)
{
    in >> inf.numerator >> inf.denominator;

    if (!in)
    {
        throw "Invalid data or logical error";
    }

    if (inf.denominator == 0)
    {
        throw "Invalid data or logical error";
    }
    int GreatestCD = __gcd(abs(inf.numerator), abs(inf.denominator));

    inf.numerator = inf.numerator / GreatestCD;
    inf.denominator = inf.denominator / GreatestCD;

    if (inf.numerator < 0 && inf.denominator < 0)
    {
        inf.numerator = abs(inf.numerator);
        inf.denominator = abs(inf.denominator);
    }
    else if (inf.numerator < 0 || inf.denominator < 0)
    {
        inf.numerator = -abs(inf.numerator);
        inf.denominator = abs(inf.denominator);
    }
    return in;
};

//Other airthemetic operators
Fraction Fraction::operator+(const Fraction &src)
{
    if (this->denominator == src.denominator)
    {
        return Fraction(this->numerator + src.numerator, this->denominator);
    }
    else
    {
        return Fraction(this->numerator * src.denominator + this->denominator * src.numerator,
                        this->denominator * src.denominator);
    }
};
Fraction Fraction::operator-(const Fraction &src)
{
    if (this->denominator == src.denominator)
    {
        return Fraction(this->numerator - src.numerator, this->denominator);
    }
    else
    {
        return Fraction(this->numerator * src.denominator - this->denominator * src.numerator,
                        this->denominator * src.denominator);
    }
};
Fraction Fraction::operator*(const Fraction &src)
{
    return Fraction(this->numerator * src.numerator, this->denominator * src.denominator);
};
Fraction Fraction::operator/(const Fraction &src)
{
    return Fraction(this->numerator * src.denominator, this->denominator * src.numerator);
};