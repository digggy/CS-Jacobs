/*
CH08-320142
Problem 4.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#define _USE_MATH_DEFINES

#include<cmath>
#include <iostream>
#include "Shapes.h"

using namespace std; 

//default Constructor for shape
Shape::Shape() : name("Default Shape"){}

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}
//setter of shape name
void Shape::setName(std::string n){
    name =n;
}
//getter of shape name
string Shape::getName(){
    return name;
}

//defualt Constructor for Centered Shape
CenteredShape::CenteredShape(): Shape("Default Centered Shape") {
    x=0;
    y=0;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): 
Shape(n) 
{
	x = nx;
	y = ny;
}
//setters of X and Y
void CenteredShape::setX(double nx){
    x=nx;
}
void CenteredShape::setY(double ny){
    y=ny;
}

//getters of X and Y
double CenteredShape::getX(){
    return x;
}
double CenteredShape::getY(){
    return y;
}

RegularPolygon::RegularPolygon() : 
        CenteredShape("Default Regular Polygon",0,0)
{
        EdgesNumber=0;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}
//setter of RegularPolygon
void RegularPolygon::setEdgesNumber(int nl){
    EdgesNumber=nl;
}
//getter of RegularPolygon
int RegularPolygon::getEdgesNumber(){
    return EdgesNumber;
}

//new class Rectangle Constructor
Rectangle::Rectangle() : 
    RegularPolygon("Default Rectangle",0,0,4)
{
    nwidth=0;
    nheight=0;
}
Rectangle::Rectangle(const string& n,double nx,double ny,double nwidth,double nheight) :
     RegularPolygon(n,nx,ny,4)
{
        this->nwidth=nwidth;
        this->nheight=nheight;
}
//setter for Rectangle width and height
void Rectangle::setnWidth(double width){
    nwidth=width;
}
void Rectangle::setnheight(double height){
	nheight=height;
}
//getter  for Rectangle width and height
double Rectangle::getnWidth(){
    return nwidth;
}
double Rectangle::getnHeight(){
    return nheight;
}

//Method for Area of Rectangle class
double Rectangle::area(){
    return nwidth*nheight;
}

//Method for Perimeter of Rectangle class
double Rectangle::perimeter(){
    return 2*(nwidth+nheight);
}

//new class Square Constructor
Square::Square():Rectangle("Default Square",0,0,0,0)
{
    nside=0;
}

Square::Square(const string& n,double nx,double ny,double nside) :
    Rectangle(n,nx,ny,nside,nside)
{
    this->nside=nside;
}
//setters for square
void Square::setnside(double side){
	nside=side;
}

//getter for square
double Square::getnside(){
	return nside;
}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}
//setters for Circle
void Circle::setRadius(double radius){
	Radius=radius;
}
//get for Circle
double Circle::getRadius(){
    return Radius;
}
//Area and Perimeter of Circle
double Circle::area(){
    return M_PI*Radius*Radius;
}
double Circle::perimeter(){
    return 2*M_PI*Radius;
}
