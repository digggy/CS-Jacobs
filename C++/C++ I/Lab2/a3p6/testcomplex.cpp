/*
CH08-320142
Problem 3.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include"Complex.h"
using namespace std;

int main(int argc,char** argv){
    //First complex instance
    Complex a(5,2);
    cout<<"The first number : ";
    a.print();

    //Second complex instance
    Complex b(6,3);
    cout<<"The second number : ";
    b.print();
    cout<<endl;

    //conjugate of first instance
    cout<<"The conjugate of first number is"<<endl;
    a.conjugate().print();

    //Printing out the operations 
    cout<<"Printing out the Sum"<<endl;
    a.add(b).print();
    cout<<"Printing out the difference"<<endl;
    a.sub(b).print();
    cout<<"Printing out the product"<<endl;
    a.mul(b).print();

    return 0;
}
