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

// A function to test
string pass(bool src)
{
    if (src)
    {
        return " is ture.";
    }
    else
    {
        return " is false.";
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

        cout << "\nLogical Operators" << endl;
        cout << "A < B " << pass(A < B) << endl;
        cout << "B > A " << pass(B > A) << endl;
        cout << "A <= B " << pass(A <= B) << endl;
        cout << "B >= A " << pass(B >= A) << endl;
        cout << "A == A " << pass(A == A) << endl;
        cout << "A != B " << pass(A != B) << endl;

        cout << "\nOther Airthemetic Operators" << endl;

        //Assignment operator
        Fraction D = C + B;

        //Other Airthemetic operators
        cout << "C + B = " << D;
        cout << "C - B = " << C - B;
        cout << "C * B = " << C * B;
        cout << "C / B = " << C / B;

        char in;

        cout << "Do you want to continue (y/Y): ";
        cin >> in;

        if (in == 'y' || in == 'Y')
        {
            system("clear");

            //Asking user for a fractions
            cout << "Input the Fractions A " << endl;
            Fraction Input1;
            cin >> Input1;
            cout << "Input the Fractions B " << endl;
            Fraction Input2;
            cin >> Input2;

            cout << "\nThe results are " << endl;
            cout << "A + B = " << Input1 + Input2;
            cout << "A - B = " << Input1 - Input2;
            cout << "A * B = " << Input1 * Input2;
            cout << "A / B = " << Input1 / Input2 << endl;
        }
    }
    catch (char const *str)
    {
        cout << str << endl;
    }

    return 0;
}