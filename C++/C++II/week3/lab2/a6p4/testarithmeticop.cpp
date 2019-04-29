/*
CH08-320143
a6p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include "Fraction.h"
#include <stdlib.h>
using namespace std;

int pass = 0, fail = 0;

// A function to test
string test_it(bool src)
{
    if (src)
    {
        pass++;
        return " passes\n";
    }
    else
    {
        fail++;
        return "fails\n";
    }
}

int main(int argc, char **argv)
{
    try
    {
        Fraction A("-1/2");
        Fraction B("1/2");
        Fraction C("3/2");

        // Printing A B and C
        cout << "A = " << A;
        cout << "B = " << B;
        cout << "C = " << C;

        // Assignment operator
        //Finding various results for B and A
        Fraction Sum = A + B;
        Fraction Diff = A - B;
        Fraction Mul = A * B;
        Fraction Div = A / B;
        //Finding various results for B and C
        Fraction Su = C + B;
        Fraction Dif = C - B;
        Fraction Mu = C * B;
        Fraction Di = C / B;

        cout << "\nTesting Arithmetic Operator : " << endl;

        // Other Airthemetic operators
        cout << "Test : A + B  " << test_it(A + B == Sum);
        cout << "Test : A - B  " << test_it(A - B == Diff);
        cout << "Test : A * B  " << test_it(A * B == Mul);
        cout << "Test : A / B  " << test_it(A / B == Div);
        cout << "Test : C + B  " << test_it(C + B == Su);
        cout << "Test : C - B  " << test_it(C - B == Dif);
        cout << "Test : C * B  " << test_it(C * B == Mu);
        cout << "Test : C / B  " << test_it(C / B == Di);

        // Total Result
        cout << "\nResult" << endl;
        cout << pass << " cases passed." << endl;
        cout << fail << " cases failed." << endl;
        cout << "_____________________________________" << endl;
    }
    catch (char const *str)
    {
        cout << str << endl;
    }

    return 0;
}