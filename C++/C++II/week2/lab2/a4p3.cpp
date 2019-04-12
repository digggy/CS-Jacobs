/*
CH08-320143
a4p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    //A set container
    set<int> A;
    multiset<int, less<int>> B;
    multiset<int> intersect;

    //A iterator for the set container
    int input;
    cin >> input;
    while (input >= 0)
    {
        A.insert(input);
        B.insert(input);
        cin >> input;
    }
    //Printing the set out
    cout << "Printing Set\n";
    set<int>::iterator pos;
    for (pos = A.begin(); pos != A.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;

    //Printing multiset B
    cout << "Printing Multiset\n";
    multiset<int>::iterator posb;
    for (posb = B.begin(); posb != B.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    //Erasing the elements 11
    A.erase(11);
    B.erase(11);

    //Printing the set out
    cout << "\nAfter Erasing 11 \n\nPrinting Set\n";
    for (pos = A.begin(); pos != A.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;

    //Printing multiset B
    cout << "Printing Multiset\n";
    for (posb = B.begin(); posb != B.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    //Insertion of 5 and 421
    A.insert(5);
    A.insert(421);

    //finding the Union
    multiset<int> uni;
    set_union(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(uni, uni.begin()));

    cout << "\nPrinting Union\n";
    for (posb = uni.begin(); posb != uni.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    //finding the Intersection
    multiset<int> inter;
    set_intersection(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(inter, inter.begin()));

    cout << "Printing Intersection\n";
    for (posb = inter.begin(); posb != inter.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    //finding the Difference
    set<int> diff;
    set_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(diff, diff.begin()));

    cout << "Printing Difference\n";
    for (posb = diff.begin(); posb != diff.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    //finding the Difference
    set<int> adiff;
    set_symmetric_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(adiff, adiff.begin()));

    cout << "Printing Symmetric Difference\n";
    for (posb = adiff.begin(); posb != adiff.end(); posb++)
    {
        cout << *posb << " ";
    }
    cout << endl;

    return 0;
}
