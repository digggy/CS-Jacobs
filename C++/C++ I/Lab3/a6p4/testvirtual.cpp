/*
CH08-320142
Problem 6.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

string rcolor (string colors[]);

const int num_obj = 20;

int main() {

	//Randomize
	srand(static_cast<unsigned int>(time(0)));

	int obj_create=0;
	int col_create;
	
	//Setting colors
	const char* colors[4] = {"RED","YELLOW","BLUE","GREEN"};
	
	Area *list[num_obj];			
	
	// (1) Array of pointers of objects of size 6
	int index = 0;					
	
	// (2) Initializing the value of Inital index to  0
	double sum_area = 0.0;
	
	// (3) Initializing the value of sum_area to 0.0
	double sum_perimeter = 0.0;			
	
	
	for (int i=0;i<num_obj;i++){
		obj_create = rand() % 4 +1;
		col_create = rand() % 4;

		double num_a=rand()%50+1;
		double num_b=rand()%50+1;
	
		switch (obj_create){
			case 1 :
				list[i] = new Rectangle(colors[col_create],num_a,num_b);
				break;
			case 2 :
				list[i]= new Square(colors[col_create],num_a);
				break;
			case 3 :
				list[i]= new Circle(colors[col_create],num_a);
				break;
			case 4 : 
				//swapping values if the outside radius is smaller than the inside radius
				
				if (num_a<num_b){
					double temp=num_a;
					num_a=num_b;
					num_b=temp;
				}
				list[i]= new Ring(colors[col_create],num_a,num_b);
				break;
		}

	}

	while (index < num_obj) {					
		// (7) loop until the index is equal to num_obj that is == 6  
		cout<<endl<<" ==== >>>>>>> Object No "<<index+1<<endl;	
		
		(list[index])->getColor();	

		// (8) Calculating the area and perimeter of the object in the given list 
		double area = list[index]->calcArea();
		double perimeter = list[index]->calcPerimeter();
		
		index++;
		sum_area += area;
		sum_perimeter+=perimeter;
		
		cout<<"\n------------------------------------------\n";
	}
	cout<<"\n#########################################\n";
	
	// (9) Printing the total area of objects
	cout << "\nThe total area is "<< sum_area << " units " << endl;	
	
	//(10) Printing the total perimeter of the objects
	cout<<"\n\nThe total perimeter is "<<sum_perimeter<<" units "<<endl;
	
	cout<<"\n#########################################\n";
	
	return 0;
}
