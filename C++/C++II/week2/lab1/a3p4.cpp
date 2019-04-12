/*
CH08-320143
a3p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    deque<double> A;
    double input;
    cin >> input;
    while (input != 0)
    {
        if (input > 0)
        {
            A.push_back(input);
        }
        else
        {
            A.push_front(input);
        }
        cin >> input;
    }

    deque<double>::iterator pos;
    cout << "Printing the elements\n";
    for (pos = A.begin(); pos != A.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;

    // Inserting the element 0 in the deque list
    pos = A.begin();
    while (*pos < 0)
    {
        pos++;
    }
    A.insert(pos, 0);

    //Printing the list
    cout << "\nPrinting the elements after inserting 0\n";
    for (pos = A.begin(); pos != A.end(); pos++)
    {
        if (pos != A.begin())
        {
            cout << " ;";
        }
        cout << *pos;
    }

    cout << endl;
    return 0;
}
