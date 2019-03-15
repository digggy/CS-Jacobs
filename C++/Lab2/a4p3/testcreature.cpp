/*
CH08-320142
Problem 4.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include"Creature.h"
using namespace std;

int main()
{ 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();
    
    cout<<"\nCreating a Dragon.\n";
    Dragon d;
    d.run();
    d.breathe();
    
    cout<<"\nCreating a Treebeard.\n";
    Treebeard t;
    t.run();
    t.leechSeed();

    //blank lines
    cout<<endl<<endl;

    return 0;
} 
