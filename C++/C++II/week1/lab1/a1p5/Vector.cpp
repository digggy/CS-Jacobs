/*
CH08-320143
a1p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <cmath>
#include "Vector.h"

#include <iostream>

using namespace std;

//Empty Constructor
Vector::Vector()
{
    size = 3;
    // component = new double[3]{0, 0, 0};
}

Vector::Vector(int length)
{
    size = length;
    component = new double[length];
}

//Constructor with parameters
Vector::Vector(int nSize, double *&nComponent)
{
    size = nSize;
    component = nComponent;
}

//Destructor
Vector::~Vector()
{
    // delete[] component;
}

//Getters
int Vector::getsize() const
{
    return size;
}

double *Vector::getcomponent() const
{
    return component;
}
//Setters
void Vector::setcomponent(int pos, double value)
{
    component[pos] = value;
}

//Operator overload
ostream &operator<<(ostream &out, const Vector &vout)
{

    out << "[";
    for (int i = 0; i < vout.size; i++)
    {
        if (i == vout.size - 1)
        {
            out << vout.component[i];
        }
        else
        {
            out << vout.component[i] << ",";
        }
    }
    out << "]" << endl;
    return out;
}

istream &operator>>(istream &in, Vector &vin)
{
    in >> vin.size;
    vin.component = new double[vin.size];
    for (int i = 0; i < vin.size; i++)
    {
        in >> vin.component[i];
    }
    return in;
}

//Addtion of vectors
Vector Vector::operator+(const Vector &obj) const
{

    //setting a new component for new object
    double *nComponent = new double[size];

    for (int i = 0; i < size; i++)
    {
        //adding the elements of the component
        nComponent[i] = component[i] + obj.component[i];
    }

    Vector sum(size, nComponent);
    return sum;
}

//Difference of Vectors
Vector Vector::operator-(const Vector &obj) const
{
    //setting a new component for new object
    double *nComponent = new double[size];
    for (int i = 0; i < size; i++)
    {
        nComponent[i] = component[i] - obj.component[i];
    }
    Vector difference(size, nComponent);
    return difference;
}
