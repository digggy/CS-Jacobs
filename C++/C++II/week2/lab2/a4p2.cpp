/*
CH08-320143
a4p2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
    srand(time(0));

    //A set container
    set<int> lucky;
    //A iterator for the set container
    set<int>::iterator pos;

    while (lucky.size() < 6)
    {
        int input = rand() % 49 + 1;
        lucky.insert(input);
    }

    //Printing the set out
    cout << "\n !! Congratulations !! \n"
         << endl;
    cout << " The luck numbers are \n  ";
    for (pos = lucky.begin(); pos != lucky.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << "\n"
         << endl;
    return 0;
}
