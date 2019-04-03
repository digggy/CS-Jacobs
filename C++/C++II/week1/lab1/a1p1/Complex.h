/*
CH08-320143
a1p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

using namespace std;
class Complex
{
private:
  int real;
  int imaginary;

public:
  Complex();
  Complex(int, int);
  Complex(Complex &);
  ~Complex();

  //Set methods
  void setreal(int nr);
  void setimg(int ni);

  //Get methods
  int getreal();
  int getimg();

  //Operator overload methods
  Complex operator+(const Complex &);
  Complex operator-(const Complex &);
  Complex operator*(const Complex &);
  Complex operator=(const Complex &);

  friend ostream &operator<<(ostream &, const Complex &);
  friend istream &operator>>(istream &, Complex &);
};