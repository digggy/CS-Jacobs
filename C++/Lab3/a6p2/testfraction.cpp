/*
CH08-320142
Problem 6.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
	
	Fraction a,b;
	
	//Input the fractions A and B
	cout<<"\n---------------------------\n\n";
	
	cout<<"Enter Fraction A : \n";
	cin>>a;
	cout<<"Enter Fraction B :\n";
	cin>>b;

	//Display the fractions A and B
	cout<<"\nNumber A : "<<a<<endl;
	cout<<"Number B : "<<b<<endl<<endl;

	//Applying the operator * , / , - , +
	cout<<"The sum is         : "<<a+b<<endl;
	cout<<"The difference is  : "<<a-b<<endl;
	cout<<"The product is     : "<<a*b<<endl;
	cout<<"The quotient is    : "<<a/b<<endl;
	cout<<endl;

	///Comparision of A and B 
	if (a>b){
		cout<<"Fraction A is greater than B "<<endl;
		cout<<a<<endl<<endl;
	}else{
		cout<<"Fraction B is greater than A  : ";
		cout<<b<<endl<<endl;
	}
	
	return 0;

}
