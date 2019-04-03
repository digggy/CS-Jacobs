/*
CH08-320143
a2p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char **argv)
{
    LinkedList<int> list;
    list.pushBack(771);
    list.pushFront(11);
    list.pushFront(2);
    list.pushFront(22);
    list.pushFront(35);
    list.pushFront(71);

    cout << "\nInitially the list has " << endl;
    cout << "In the front : " << list.front() << endl;
    cout << "In the back : " << list.back() << endl;

    //Pushing front and the back
    list.pushFront(2000);
    list.pushBack(2018);
    cout << "\nAfter Modification" << endl;
    cout << "In the front : " << list.front() << endl;
    cout << "In the back : " << list.back() << endl;

    cout << "\nThe number of elements in the list is " << list.getSize() << endl;

    //Operations to delete the elements
    cout << "\nDelete Back  Element -> " << list.delBack() << endl;
    cout << "Delete Front Element -> " << list.delFront() << endl;
    cout << "In the front : " << list.front() << endl;
    cout << "In the back : " << list.back() << endl;

    cout << "\nThe number of elements in the list is " << list.getSize() << endl;

    return 0;
}