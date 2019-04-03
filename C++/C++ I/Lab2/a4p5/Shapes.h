/*
CH08-320142
Problem 4.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape {	 // base class
	private:   			   // private access modifier: could also be protected
		std::string name;  // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  
		//setter
		void setName(std::string n);
		//getter
		std::string getName();

};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center
		//setter
		void setX(double nx);
		void setY(double ny);
		//getters
		double getX();
		double getY();
};

// a regular polygon is a centered_shape with a number of edges
class RegularPolygon : public CenteredShape { 
	private: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);
		//setter
		void setEdgesNumber(int nl);
		//getter
		int getEdgesNumber();
};

class Rectangle : public RegularPolygon {
	private:
		double nwidth;
		double nheight;
	  
	public:
		Rectangle(const Rectangle& obj);
		Rectangle();
		Rectangle(const std::string&,double nx ,double ny,double nwidth,double nheight);
		//setters
		void setnWidth(double width);
		void setnheight(double height);
		//getters
		double getnWidth();
		double getnHeight();

		//Service Methods
		double area();
		double perimeter();
	
};

//Class Square
class Square : public Rectangle{
	private:
		double nside;

	public:
		Square(const Square& obj);
		Square();
		Square(const std::string&,double nx,double ny,double nside);
		//setters
		void setnside(double side);
		//getter
		double getnside();
};

// a Circle is a shape with a center and a radius
class Circle : public CenteredShape {  
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);
		//setter
		void setRadius(double radius);
		//getter
		double getRadius();
		double area();
		double perimeter();
};
    
#endif
