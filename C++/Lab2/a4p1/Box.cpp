/*
CH08-320142
Problem 3.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include "Box.h"

//constructors
Box::Box(){
	height=0;
	width=0;
	depth=0;
}

Box::Box(double newHeight,double newWidth,double newDepth){
    height=newHeight;
    width=newWidth;
    depth=newDepth;
}
//destructor
Box::~Box(){

}

//setter
void Box::setHeight(int newHeight){
    height=newHeight;
}

void Box::setWidth(int newWidth){
    width=newWidth;
}

void Box::setDepth(int newDepth){
    depth=newDepth;
}

//getter methods
double Box::getHeight(){
    return height;
}
double Box::getWidth(){
    return width;
}
double Box::getDepth(){
    return depth;
}

//service methods
double Box::volume(){
    return height*depth*width;
} 
