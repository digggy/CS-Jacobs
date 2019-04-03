/*
CH08-320143
a1p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
// #include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    Matrix a;
    Vector b;

    ifstream in1, in2;
    ofstream out1, out2;

    //First input file
    in1.open("in1.txt", ios::in);
    if (!in1.good())
    {
        cerr << "Error opening the file" << endl;
    }
    in1 >> a;
    cout << "The matrix is : \n";
    cout << a;
    cout << endl;
    in1.close();

    //The second input file
    in2.open("in2.txt", ios::in);
    if (!in2.good())
    {
        cerr << "Error opening the file" << endl;
    }

    in2 >> b;
    cout << "The vector is : ";
    cout << b;

    cout << endl;
    in2.close();

    //Opening the outputfile one
    out1.open("out1.txt", ios::out);
    if (!out1.good())
    {
        cerr << "Error opening the file" << endl;
    }

    //Printing in the console screen
    cout << "The result of Matrix A * Vector B is : ";
    cout << (a * b);

    //Writting in the file
    out1 << "The result of Matrix A * Vector B is : ";
    out1 << (a * b);
    out1.close();

    return 0;
}