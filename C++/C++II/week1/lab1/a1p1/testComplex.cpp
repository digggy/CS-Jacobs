/*
CH08-320143
a1p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
    //Declaring the Complex numbers
    Complex numa, numb;
    Complex sum, mul, diff;

    ifstream in1, in2;
    ofstream out;

    //The first file in to read the complex number from
    in1.open("in1.txt", ios::in);
    if (!in1.good())
    {
        cerr << "Error opening the file" << endl;
    }
    in1 >> numa;
    cout << "The first number is : " << numa;
    in1.close();

    //The second file in to read the complex number from
    in2.open("in2.txt", ios::in);
    if (!in2.good())
    {
        cerr << "Error opening the file" << endl;
    }
    in2 >> numb;
    cout << "The second number is : " << numb;
    in2.close();

    // Opening the output file
    out.open("output.txt", ios::out);
    if (!out.good())
    {
        cerr << "Error opening the file" << endl;
    }

    //Calculating the sum,difference and multiply

    sum = numa + numb;
    diff = numa - numb;
    mul = numa * numb;

    cout << "The results are :" << endl;
    cout << "A+B is " << sum;
    cout << "A-B is " << diff;
    cout << "A*B is " << mul;

    //Output for the file
    out << "Sum is :" << sum;
    out << "Difference is :" << diff;
    out << "Product is :" << mul;

    out.close();
}