/*
CH08-320142
Problem 5.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Shapes.h"
#include <cmath>

using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

//Constructor With Parameters
Hexagon::Hexagon(const string& n,double nx,double ny,int nl,double s,const string& c):
        RegularPolygon(n,nx,ny,nl)
{
   side=s; 
   color=c;
}

//CopyConstructor
Hexagon::Hexagon(Hexagon& obj) : 
RegularPolygon(obj.name,obj.x,obj.y,obj.EdgesNumber)
{
    side=obj.side;
    color=obj.color;
}

//Destructor
Hexagon::~Hexagon(){}

//getters for Hexagon

string Hexagon::getColor(){
    return color;
}

double Hexagon::getSide(){
    return side;
}

//setters for Hexagon
void Hexagon::setSide(double s){
    side=s;
}

void Hexagon::setColor(string c){
    color=c;
}

//Service methods

double Hexagon::area(){
    return ((3*pow(3,0.5)*pow(side,2))/2);
}

double Hexagon::perimeter(){
    return 6*side;
}  
