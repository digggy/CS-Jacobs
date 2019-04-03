/*
CH08-320142
Problem 2.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
using namespace std;
void swapping(int& a , int& b) ;
void swapping(double& x,double& y);
void swapping(const char*& str1,const char*& str2);

int main(void) {
    int a = 5, b = 10;
    double x = 5.2, y = 10.7;
    const char *str1 = "One";
    const char *str2 = "Two";

    //Printing out the values before swapping to the console
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;

    swapping(a,b);
    swapping(x,y);
    swapping(str1,str2);

    //Printing out the swapped values to the console
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    return 0;
}

// swap ints
void swapping(int& a , int& b) {
    int temp;
    temp=b;
    b=a;
    a=temp;

} 

// swap doubles
void swapping(double& x,double& y) { 
    double temp;
    temp=x;
    x=y;
    y=temp;


} 

 // swap char pointers
void swapping(const char*& str1,const char*& str2) {
    const char* temp;
    temp=str2;
    str2=str1;
    str1=temp;


}


