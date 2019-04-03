/*
CH08-320142
Problem 6.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

//function to find the gcd
int Fraction::gcd(int a, int b)
{

	// Recursive implementations  of GCD of two numbers;
 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // Base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
     return Fraction::gcd(a-b, b); 

    return Fraction::gcd(a, b-a); 

} 

//function to find the lcm 
int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);

}

//print function 
void Fraction::print()
{
	std::cout << num << "/" << den << std::endl;
}

// Overloading the >> and << operators 
istream& operator>>(istream& in, Fraction& term){
	int denominator;
	in>>term.num>>denominator;

	//check if the denominator is 0
	while (denominator == 0){
		cout<<"------ Invalid Expression -------"<<endl;
		cout<<"        Denominator == 0 \n"<<endl;
		cout<<"Enter New Denominator  : ";
		cin>>denominator;
	}
	term.den=denominator;
	return in;
}

ostream& operator<<(ostream& out, const Fraction& term){

	//If the denominator == 1 then no need to show the denominator 
	if (term.den ==1){
		out<<term.num;
	}else{
		out<<term.num<<"/"<<term.den;
	}
	return out;
}

//Overloading the / and * operators

Fraction Fraction::operator*(Fraction frac_in){
	num=num*frac_in.num;
	den=den*frac_in.den;

	int number = gcd(num,den);
	//this takes the decimal numbers to least their possible forms
    num = num/number;                    
	den = den/number;
    
	return *this;

}

//this is the the multiplication of the frac_in's inverse 
//so it is a division 

Fraction Fraction::operator/(Fraction frac_in){
	num=num*frac_in.den;
	den=den*frac_in.num;

	int number = gcd(num,den);
	//this takes the decimal numbers to least their possible forms
    num = num/number;                    
	den = den/number;

	return *this;

}

//the function below calculates the sum
Fraction Fraction ::operator+(Fraction frac_in){
	num=num*lcm(den,frac_in.den)/den+frac_in.num*lcm(den,frac_in.den)/frac_in.den;
	den= lcm(den,frac_in.den);

	int number = gcd(num,den);

	//this takes the decimal numbers to least their possible forms
    num = num/number;                    
	den = den/number;

	return *this; 
}

//the function below calculates the difference
Fraction Fraction ::operator-(Fraction frac_in){

	num=num*lcm(den,frac_in.den)/den-frac_in.num*lcm(den,frac_in.den)/frac_in.den;
	den= lcm(den,frac_in.den);

	return *this; 
}

//boolean function of comparision of fractions
bool Fraction::operator<(Fraction frac_in){	
	if (((double)num/(double)den)<((double)frac_in.num/(double)frac_in.den)){		
		return true;
	}else{
		return false;
	}
}

//boolean function of comparision of fractions
bool Fraction::operator>(Fraction frac_in){

	if (((double)num/(double)den)>((double)frac_in.num/(double)frac_in.den)){		
		return true;
	}else{
		return false;
	}
}

//operator for =
Fraction Fraction ::operator=(Fraction& frac_in){
	num=frac_in.num;
	den=frac_in.den;
	return *this;
}