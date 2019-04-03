/*
CH08-320143
a1p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
    real = imaginary = 0;
}

Complex::Complex(int r, int i)
{
    //paramatic constructor
    real = r;
    imaginary = i;
}
Complex::Complex(Complex &copy)
{
    //Copy constructor
    real = copy.real;
    imaginary = copy.imaginary;
}

Complex::~Complex()
{
    //Distructor
}

// Setter methods
void Complex::setreal(int r)
{
    real = r;
}

void Complex::setimg(int i)
{
    imaginary = i;
}
// Getter method
int Complex::getreal()
{
    return real;
}

int Complex::getimg()
{
    return imaginary;
}

//Operator overload to multiply
Complex Complex::operator*(const Complex &input)
{
    Complex mul;
    mul.real = real * input.real - imaginary * input.imaginary;
    mul.imaginary = real * input.imaginary + imaginary * input.real;
    return mul;
}

//Operator overload to add
Complex Complex::operator+(const Complex &input)
{
    Complex num;
    num.real = real + input.real;
    num.imaginary = imaginary + input.imaginary;
    return num;
}

//Operator overload to substract
Complex Complex::operator-(const Complex &input)
{
    Complex sub;
    sub.real = real - input.real;
    sub.imaginary = imaginary - input.imaginary;
    return sub;
}

//Assignment operator
Complex Complex::operator=(const Complex &input)
{
    real = input.real;
    imaginary = input.imaginary;
    return *this;
}

//Output  operator overload
ostream &operator<<(ostream &out, const Complex &input)
{
    if (input.imaginary)
    {
        out << noshowpos << input.real << showpos << input.imaginary << "i" << endl; //using showpos to print '+' in required conditions
    }
    else
    {
        out << noshowpos << input.real << showpos << endl;
    }
    return out;
}

// Input operator overload
istream &operator>>(istream &in, Complex &num)
{
    in >> num.real >> num.imaginary;
    return in;
}