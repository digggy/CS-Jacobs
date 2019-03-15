/*
CH08-320142
Problem 6.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
using namespace std;

#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"
 
const int num_obj = 7;
int main() {
	Area *list[num_obj];			
	// (1) Array of pointers of objects of size 6
	int index = 0;					
	// (2) Initializing the value of Inital index to  0
	double sum_area = 0.0;
	// (3) Initializing the value of sum_area to 0.0
	double sum_perimeter = 0.0;			

	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);	
	// (4) blue_ring object of Ring Class created 
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	cout<<"Creating Square :";
	Square white_square("WHITE",4);

	list[0] = &blue_ring;			 
	// (5) The first element of the array list is the &blue_ring

	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	list[6] = &white_square;
	

	while (index < num_obj) {					
		// (7) loop until the index is equal to num_obj that is == 6  
		
		(list[index])->getColor();	

		double area = list[index]->calcArea();
		double perimeter = list[index]->calcPerimeter();
		index++;
		cout<<perimeter<<endl;
		// (8) Calculating the area of the object in the given list 
		sum_area += area;
		sum_perimeter+=perimeter;
	}
	cout<<"-------------------------------------\n";
	// (9) Printing the total area of objects
	cout << "\nThe total area is "<< sum_area << " units " << endl;	
	//(10) Printing the total perimeter of the objects
	cout<<"\n\nThe total perimeter is "<<sum_perimeter<<" units "<<endl;
	cout<<"-------------------------------------\n";
	return 0;
}

//Question No a)
/*	                ( Area )                     
                     /    \   
				Circle	  Rectangle
				  /		      \
			    Ring		 Square	
														*/