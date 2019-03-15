/*
CH08-320142
Problem 5.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include<iostream>
#include<string>
#include "Shapes.h"

using namespace std;

int main (int argc,char** argv){
    //Creating Hexagons a b and c

    Hexagon a("HexagonOne",1,2,6,2,"red"); 
    Hexagon b("HexagonTwo",0,0,6,10,"yellow");
    Hexagon c(b);
    //setting new 
    c.setColor("Black");

    //Printing the Area and Perimeters
    
    //First Hexagon 
    cout<<"-------------------"<<endl;
    a.printName();
    cout<<"The area is : "<<a.area()<<endl;
    cout<<"The perimeter is : "<<a.perimeter()<<endl;

    //Second Hexagon 
    cout<<"-------------------"<<endl;
    b.printName();
    cout<<"The area is : "<<b.area()<<endl;
    cout<<"The perimeter is : "<<b.perimeter()<<endl;

    //Third Hexagon
    //This one is copied 
    cout<<"-------------------"<<endl;
    c.printName();
    cout<<"The area is : "<<c.area()<<endl;
    cout<<"The perimeter is : "<<c.perimeter()<<endl;

   
    return 0;
}
