/*
CH08-320142
Problem 4.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include"Creature.h"

using namespace std;

//Creature Constructor
Creature::Creature(): distance(10)
{
    cout<<"=> Constructor Creature"<<endl;
}    
Creature::~Creature(){
    cout<<"Destructor Creature"<<endl;
}    

void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

//Wizard Constructor
Wizard::Wizard() : distFactor(3)
{
    cout<<"=> Constructor Wizard"<<endl;
}
Wizard::~Wizard(){
    cout<<"Destructor Wizard"<<endl;
}  

void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n"<<endl;
}

//Dragon Constructor
Dragon::Dragon():flame(2)
{
    cout<<"=> Constructor Dragon"<<endl;
}
Dragon::~Dragon(){
    cout<<"Destructor Dragon"<<endl;
}
//Dragon Breathe
void Dragon::breathe() const
{
    cout<<"Breathe flame : "<<(flame*distance)<< " meters!\n"<<endl;
}

//Treebeard Constructor
Treebeard::Treebeard() : seeds(4)
{
    cout<<"=> Constructor Treebeard"<<endl;
}
Treebeard::~Treebeard(){
        cout<<"Destructor Treebeard"<<endl;
}
//Treebeard Special Ability
void Treebeard::leechSeed() const {
    cout<<"The Leechseed Range : "<<(seeds*distance)<<" meters!\n"<<endl;
}
