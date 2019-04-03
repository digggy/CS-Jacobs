
/*
CH08-320143
a2p2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, char **argv)
{
    Queue<int> line(10);
    cout << "\nFor the int" << endl;
    //Pushing the elements inside the stack
    for (int i = 10; i < 20; i++)
    {
        line.push(i);
    }

    cout << "Popping the elements out" << endl;
    //Popping out all the values from the queue
    for (int i = line.getNumEntries(); line.getNumEntries() > 0; i++)
    {
        int out;
        line.pop(out);
        cout << out << " ";
    }
    cout << endl;

    //---The below one is for a char type
    ////////////////////////////////////////

    Queue<char> cqueue(10);
    cout << "\nFor the char" << endl;

    //Pushing the elements inside the stack
    for (int i = 97; i < 107; i++)
    {
        char sendtoqueue = (char)i;
        cqueue.push(sendtoqueue);
    }

    cout << "Popping the elements out" << endl;
    //Popping out all the values from the queue
    for (int i = cqueue.getNumEntries(); cqueue.getNumEntries() > 0; i++)
    {
        char out;
        cqueue.pop(out);
        cout << out << " ";
    }
    cout << endl;

    return 0;
}