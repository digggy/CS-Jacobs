/*
CH08-320143
a4p6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <set>
#include "Access.h"
using namespace std;

int main(int argc, char **argv)
{
    Access A;
    //Activating codes and levels
    A.activate(123456, 1);
    A.activate(999999, 5);
    A.activate(187692, 9);
    //Input of the code
    unsigned long inputcode;
    cout << "Input the code\n";
    cin >> inputcode;

    //Ask until the code is correct
    while (!A.isactive(inputcode, 5))
    {
        cout << "!! Door Didnot Open : Try Again !!\n";
        cin >> inputcode;
    }
    cout << "!! Door Opened !!\n";
    A.deactivate(inputcode);
    A.change(999999, 8);
    A.activate(111111, 7);
    //Ask the code again
    cout << "\n--------------------";
    cout << "\nInput the code Again\n";
    cin >> inputcode;

    //Ask until the code is correct
    while (!A.isactive(inputcode, 7))
    {
        cout << "!! Door Didnot Open : Try Again !!\n";
        cin >> inputcode;
    }
    cout << "!! Door Opened !!\n";
    return 0;
}
