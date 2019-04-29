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

int pass = 0, fail = 0, cases = 0;

void test_it(bool src)
{
    if (src)
    {
        pass++;
        cases++;
        cout << "Test " << cases << " passed." << endl;
    }
    else
    {
        fail++;
        cases++;
        cout << "Test " << cases << " failed." << endl;
    }
}

int main(int argc, char **argv)
{
    cout << "\nTesting the exceptions" << endl;
    // Case 1
    try
    {
        Fraction A(1, 2);
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 2
    try
    {
        Fraction B("-3/4");
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 3
    try
    {
        Fraction C("1/5");
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 4
    try
    {
        Fraction D("-1/5");
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 5
    try
    {
        Fraction E("-11/5");
        Fraction newFrac = E;
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 6
    try
    {
        Fraction E("2/2");
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }

    // Case 7
    try
    {
        Fraction E("1/4");
        Fraction newFrac(E + E);
        test_it(true);
    }
    catch (char const *str)
    {
        cout << str << endl;
        test_it(false);
    }
    // Total Result
    cout << "\nResult" << endl;
    cout << pass << " cases passed." << endl;
    cout << fail << " cases failed." << endl;
    cout << "_____________________________________" << endl;

    return 0;
}