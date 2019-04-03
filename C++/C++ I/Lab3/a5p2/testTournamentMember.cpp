/*
CH08-320142
Problem 5.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include "TournamentMember.h"

using namespace std;

int main (int argc,char** argv){
    
    char fname [31]= "Ankit";
    char lname [32]= "Koirala";
    char date [11]= "2018-11-11";
    
    //Constructor call
    TournamentMember ankit (fname,lname,date,18,"Nepali");
    
    //Changing the static property location
    ankit.setLocation("Germany");
    
    //Calling print method 
    ankit.print();
    return 0;
}