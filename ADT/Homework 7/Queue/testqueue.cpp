#define SIZE 6
#include <iostream>
#include "Queue.h"

int main(int argc, char **argv)
{
    //Declaring the queue
    Queue<int> list;

    //Enqueue the items to the queue
    cout << "\nEnqueueing the following items"
         << endl;
    cout << " A <- B means A is infront of B in Queue \n\n";
    cout << "QUEUE START  ";
    for (int i = 0; i < SIZE; i++)
    {
        if (i + 1 != SIZE)
        {
            cout << i + 1 << " <- ";
        }
        else
        {
            cout << i + 1 << "";
        }
        list.enqueue(i + 1);
    }
    cout << " QUEUE END";

    cout << "\n\nDequeuing the elements out " << endl;

    //Popping the items to the queue
    for (int i = 0; i < SIZE; i++)
    {
        //Checking if the queue is empty
        if (!list.isEmpty())
        {
            cout << list.dequeue() << endl;
        }
        else
        {
            cout << "\nQueue Underflow\n";
        }
    }
    return 0;
}