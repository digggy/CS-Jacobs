/*
CH08-320143
a6p3.cpp
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
        Fraction C(1, 4);

        //Printing A B and C
        cout << "A = " << A;
        cout << "B = " << B;
        cout << "C = " << C;

        cout << "\nTesting Relational Operators :" << endl;
        cout << "A < B " << test_it(A < B);
        cout << "B > A " << test_it(B > A);
        cout << "A <= B " << test_it(A <= B);
        cout << "B >= A " << test_it(B >= A);
        cout << "A == A " << test_it(A == A);
        cout << "A != B " << test_it(A != B);

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