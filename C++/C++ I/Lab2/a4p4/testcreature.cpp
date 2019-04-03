/*
CH08-320142
Problem 4.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include"Creature.h"
using namespace std;

int main()
{ 
    char input=' ';
    Wizard* nW;
    Dragon* nD;
    Treebeard* nT;

    while (input !='q'){
    cout <<"-------------------"<<endl;    
    cout <<"Enter your choice :(w)-(1)-(2)-(q) : ";
    cin>>input;
    cout <<"-------------------"<<endl;
        switch (input){
            case 'w':
                cout<<"Creating Wizard"<<endl;
                nW=new Wizard;
                nW->run();
                nW->hover();
                delete nW;
                break;
            case '1':
                cout<<"Creating Dragon"<<endl;
                nD=new Dragon;
                nD->run();
                nD->breathe();
                delete nD;
                break;
            case '2':
                cout<<"Creating Treebeard"<<endl;
                nT=new Treebeard;
                nT->run();
                nT->leechSeed();
                delete nT;
                break;
        }
    }
    //blank lines
    cout<<endl<<endl;
    return 0;
} 
