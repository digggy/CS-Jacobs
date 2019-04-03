
/*
CH08-320143
a2p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, char **argv)
{
    //Queue with 10 elements declared
    Queue<int> line(10);
    cout << "\nQueue for the Int" << endl;
    //Pushing the elements inside the stack
    for (int i = 10; i < 20; i++)
    {
        line.push(i);
    }
    //Resizing the queue
    line.resize(5);
    cout << "\nThe Queue is resized to " << line.getSize() << " elements" << endl;

    cout << "\nPopping the elements out" << endl;
    //Popping out all the values from the queue
    for (int i = line.getNumEntries(); line.getNumEntries() > 0; i++)
    {
        int out;
        line.pop(out);
        cout << out << " ";
    }
    cout << endl;

    return 0;
}
