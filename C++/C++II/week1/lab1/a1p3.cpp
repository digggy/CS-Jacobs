/*
CH08-320143
a1p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
using namespace std;

class A
{
  int x;

public:
  void setX(int i) { x = i; }
  void print() { cout << x; }
};

class B : virtual public A
{
public:
  B()
  {
    cout << "Constructor B called \n";
    setX(10);
  }
};

class C : virtual public A
{
public:
  C()
  {
    cout << "Constructor C called \n";
    setX(20);
  }
};

class D : public B, public C
{
public:
  D()
  {
    cout << "Constructor D called \n";
    // setX(40);
  }
  //If you uncomment the line above it would print 40
};

int main()
{
  /*
    There is was an error => error: request for member ‘print’ is ambiguous
    this is because since the classes B and C both inherit the method print when the class D 
    calls the print method then there is a ambiguity since there are two print methods (that are in class C and B).
    Thus there is an error because it get confused which method to call as they have the same name and are 
    inherited from the same parent class.

    I have fixed the error by adding virtual as virtual inheritance ensures only one copy of a base class's member 
    variables are inherited by grandchild derived classes.
  */

  D d;
  d.print();
  return 0;
}