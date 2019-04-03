/*
CH08-320143
a1p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include <iostream>
#include "Vector.h"

using namespace std;

class Matrix
{
private:
  int row;
  int col;
  double **elements;

public:
  //Constructors
  Matrix();
  // Matrix(int, int, double **&);

  //Destructor
  ~Matrix();

  //Matrix operator overloading
  Matrix operator+(const Matrix &);
  Matrix operator-(const Matrix &);
  Vector operator*(const Vector &);

  friend ostream &operator<<(ostream &, const Matrix &);
  friend istream &operator>>(istream &, Matrix &);
};
