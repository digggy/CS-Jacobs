/*
CH08-320143
a1p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include "Matrix.h"

#include <iostream>
using namespace std;
Matrix::Matrix()
{
    row = 0;
    col = 0;
}

Matrix::~Matrix()
{
}

Vector Matrix::operator*(const Vector &vin)
{
    if (this->col == vin.getsize())
    {

        Vector out(this->row);

        for (int i = 0; i < this->row; i++)
        {
            int val = 0;
            for (int j = 0; j < this->col; j++)
            {
                val = val + this->elements[i][j] * vin.getcomponent()[j]; //
            }
            out.setcomponent(i, val);
        }

        return out;
    }
    else
    {
        cout << "The matrix and the vectors are not compatible \n Here is your Initial Vector : ";
    }
    return vin;
}

ostream &operator<<(ostream &out, const Matrix &input)
{
    for (int i = 0; i < input.row; i++)
    {
        for (int j = 0; j < input.col; j++)
        {
            out << input.elements[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Matrix &input)
{
    in >> input.row >> input.col;

    input.elements = (double **)malloc(sizeof(double *) * input.row);
    if (input.elements == NULL)
    {
        exit(0);
    }
    for (int i = 0; i < input.row; i++)
    {
        input.elements[i] = (double *)malloc(sizeof(double) * input.col);
        if (input.elements[i] == NULL)
        {
            exit(0);
        }
    }

    for (int i = 0; i < input.row; i++)
    {
        for (int j = 0; j < input.col; j++)
        {
            in >> input.elements[i][j];
        }
    }
    return in;
}