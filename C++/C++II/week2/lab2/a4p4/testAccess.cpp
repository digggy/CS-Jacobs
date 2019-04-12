/*
CH08-320143
a4p4.cpp
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

    //Activating Codes
    A.activate(123456);
    A.activate(999999);
    A.activate(187692);

    unsigned long inputCode;
    cout << "Input the Code\n";
    cin >> inputCode;

    while (!A.isactive(inputCode))
    {
        cout << "Wrong Code :Input the Code Again \n";
        cin >> inputCode;
    }
    cout << "Door Opened \n";

    A.deactivate(inputCode);
    A.deactivate(999999);
    A.activate(111111);

    //Asking for input code again
    cout << "\n--------------------\n";
    cout << "\nInput the Code Again\n";
    cin >> inputCode;
    while (!A.isactive(inputCode))
    {
        cout << "Wrong Code :Input the Code Again \n";
        cin >> inputCode;
    }
    cout << "Door Opened Again\n --- Welcome ---\n";

    return 0;
}
