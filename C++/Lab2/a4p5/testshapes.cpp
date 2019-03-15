/*
CH08-320142
Problem 4.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "Shapes.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv) {
  
  //constructing the instances of Square,Circle and Rectangle  
  Circle c("first circle", 3, 4, 6);
  Square s("SQUARE",1,1,8);
  Rectangle r("Rectangle",1,5,6,4);

  //Circle
  cout<<"The First Shape ----------"<<endl;
  c.printName();
  cout<<"The area is : "<<c.area()<<endl;
  cout<<"The perimeter is : "<<c.perimeter()<<endl<<endl;
 
  //Rectangle
  cout<<"The Second Shape ---------"<<endl;
  r.printName();
  cout<<"The area is : "<<r.area()<<endl;
  cout<<"The perimeter is : "<<r.perimeter()<<endl<<endl;

 //Square
  cout<<"The Third Shape ----------"<<endl;
  s.printName();
  cout<<"The area is : "<<s.area()<<endl;
  cout<<"The perimeter is : "<<s.perimeter()<<endl<<endl;
  
  return 0;
}
