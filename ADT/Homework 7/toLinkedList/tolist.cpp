#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char **argv)
{
    //Declaring a LinkedList A
    LinkedList A;

    //Declaring a Binary Search Tree B
    BST B;
    cout << "\nInserting into the binary tree \n";
    for (int i = 8; i > 0; i--)
    {
        cout << i * i << " ";
        B.insert(i * i);
    }
    //Printing the BST inoder
    cout << "\n\nPrinting all the values inoder in BST \n";
    B.printBST();

    //Converting the BST to a sorted linked list
    cout << "\n\nConverting it to BST" << endl;
    B.BSTtoList(A);

    //Printing the linked list
    cout << "\nPrinting all the values in Linked List \n";
    A.print_All();

    return 0;
}