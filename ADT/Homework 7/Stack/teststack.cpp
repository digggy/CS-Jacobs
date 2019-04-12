
#include <iostream>
#include "Stack.h"

#define SIZE 6
using namespace std;

int main(int argc, char **argv)
{
    //Declaring the stack

    Stack<int> list(SIZE);
    // Stack<int> list;

    //Pushing the items to the stack
    for (int i = 0; i < SIZE; i++)
    {
        list.push(i + 1);
    }

    cout << "\nPopping the elements out " << endl;

    //Popping the items to the stack
    for (int i = 0; i < SIZE; i++)
    {
        //Checking if the stack is empty
        if (!list.isEmpty())
        {
            cout << list.pop() << endl;
        }
        else
        {
            cout << "\nList Underflow\n";
        }
    }

    return 0;
}