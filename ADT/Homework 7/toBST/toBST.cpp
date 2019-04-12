#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char **argv)
{
    //Declaring a LinkedList A
    LinkedList A;
    cout << "The linked List is :\n";
    for (int i = 10; i < 16; i++)
    {
        A.push(i);
    }
    A.print_All();
    cout << "\nPrinting all the values in BST \n\n";
    //Declaring a Binary Search Tree B
    BST B;
    //List to BST
    A.toBTS(B);
    //Printing all the elements in the BST
    B.printBST();
    cout << endl;
    return 0;
}