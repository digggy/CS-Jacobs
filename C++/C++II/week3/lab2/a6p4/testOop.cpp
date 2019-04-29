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

int ipass = 0, ifail = 0;
int opass = 0, ofail = 0;

int main(int argc, char **argv)
{
    cout << "\nInput Fractions :" << endl;
    try
    {

        Fraction A;
        cin >> A;
        ipass++;
        try
        {
            cout << "Fraction is : " << A;
            opass++;
        }
        catch (char const *str)
        {
            cout << str << endl;
            ofail++;
        }
    }
    catch (char const *str)
    {
        cout << str << endl;
        ifail++;
    }

    try
    {

        Fraction B;
        cin >> B;
        ipass++;

        try
        {
            cout << "Fraction is : " << B;
            opass++;
        }
        catch (char const *str)
        {
            cout << str << endl;
            ofail++;
        }
    }
    catch (char const *str)
    {
        cout << str << endl;
        ifail++;
    }

    try
    {

        Fraction C;
        cin >> C;
        ipass++;
        try
        {
            cout << "Fraction is : " << C;
            opass++;
        }
        catch (char const *str)
        {
            cout << str << endl;
            ofail++;
        }
    }
    catch (char const *str)
    {
        cout << str << endl;
        ifail++;
    }

    // Total Result
    cout << "\nResult" << endl;
    cout << ipass << " input cases passed." << endl;
    cout << ifail << " input cases failed." << endl;
    cout << opass << " output cases passed." << endl;
    cout << ofail << " output cases failed." << endl;
    cout << "_____________________________________" << endl;

    return 0;
}