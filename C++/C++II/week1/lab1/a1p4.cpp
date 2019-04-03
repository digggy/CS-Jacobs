/*
CH08-320143
a1p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
using namespace std;

class A
{
    int x;

  public:
    A(int i) { x = i; }
    void print() { cout << x; }
};

class B : virtual public A
{
  public:
    B() : A(10) {}
};

class C : virtual public A
{
  public:
    C() : A(10) {}
};

class D : public B, public C
{
  public:
    D() : A(40) {}
};

int main()
{
    /*
        Here the constructor of class D seeks the empty constructor of class A because the class B and C have virtual inheritance.
        So in oder to call the constructor of A we have to have a parametric constructor in Class D as  D() : A(40) {} OR we can 
        also have an empty constructor in A setting a value for x and D will call the empty constructor in A.
        Currently the program prints 40 because it follows the first case that i mentioned.
    */
    D d;
    d.print();
    return 0;
}