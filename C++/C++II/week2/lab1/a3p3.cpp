/*
CH08-320143
a3p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

void printlist(list<int> src);
void printReverse(list<int> src, ofstream &out);

int main(int argc, char **argv)
{

    list<int> A;
    list<int> B;
    int input;
    cin >> input;

    while (input > 0)
    {
        A.push_front(input);
        B.push_back(input);
        cin >> input;
    }

    //Opening a file
    ofstream out;
    out.open("listB.txt", ios::out);
    if (!out.good())
    {
        cerr << "Error Opening the file" << endl;
    }
    cout << "\nThis is the list A" << endl;
    printlist(A);
    //New line
    cout << endl;
    printReverse(B, out);

    // Move the last element of the lists to the beginning (for both lists)
    int listA_back;
    listA_back = A.back();
    A.pop_back();
    A.push_front(listA_back);

    int listB_back;
    listB_back = B.back();
    B.pop_back();
    B.push_front(listB_back);

    // Print list A and B
    list<int>::iterator posa;
    list<int>::iterator posb;

    cout << "\nThis is the list A" << endl;
    for (posa = A.begin(); posa != A.end(); posa++)
    {
        if (posa != A.begin())
        {
            cout << ",";
        }
        cout << *posa;
    }

    cout << "\n\nThis is the list B" << endl;
    for (posb = B.begin(); posb != B.end(); posb++)
    {
        if (posb != B.begin())
        {
            cout << ",";
        }
        cout << *posb;
    }
    cout << endl;

    // Merging A and B
    A.merge(B);
    A.sort();
    cout << "\nThe merged list is \n";
    printlist(A);
    cout << endl;

    out.close();
    return 0;
}

void printlist(list<int> src)
{
    list<int>::iterator pos;
    for (pos = src.begin(); pos != src.end(); pos++)
    {
        cout << *pos << " ";
    }
}

void printReverse(list<int> src, ofstream &out)
{
    list<int>::reverse_iterator pos;
    for (pos = src.rbegin(); pos != src.rend(); ++pos)
    {
        out << *pos << " ";
    }
}