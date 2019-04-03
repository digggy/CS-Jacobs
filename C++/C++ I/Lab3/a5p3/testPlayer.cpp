/*
CH08-320142
Problem 5.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include "TournamentMember.h"

using namespace std;

int main (int argc,char** argv){
    
    char fname [31]= "Ankit";
    char lname [32]= "Koirala";
    char dob [11]= "2018-11-11";

    //Constructor call Player 1
    Player ankit (fname,lname,dob,18,"Nepali",7,"GoalKeeper",0,"Right Leg");
    
    //Copying New Values for player 2
    strcpy(fname,"Dipak");
    strcpy(lname,"Kandel");
    strcpy(dob,"1998-06-14");

    //Constructor call Player 2
    Player dipak (fname,lname,dob,18,"Nepali",8,"Midfilder",0,"Right leg");
    
    //Compying New Values for player 2
    strcpy(fname,"Aman");
    strcpy(lname,"KC");
    strcpy(dob,"1999-04-24");

    //Constructor call Player 3
    Player aman (fname,lname,dob,18,"America",59,"Defender",0,"Left leg");
    

    //Changing the static property location
    Player::setLocation("Germany");

    ankit.addGoal(); //adding a goal for Player ankit
    
    //Calling print method 
   
    ankit.print();
    dipak.print();
    aman.print();

    return 0;
}