/*
CH08-320142
Problem 5.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include "TournamentMember.h"

using namespace std;

//Constructor for Tournament Member
TournamentMember::TournamentMember(char fname[31],char lname[32],
char dob[11],int age,string nationality){

    cout<<"\nConstructor for TournamentMember\n"<<endl<<endl;
    //copying the values of the char []
    strcpy(this->fname,fname);
    strcpy(this->lname,lname);
    strcpy(this->dob,dob);
    this->age=age;
    this->nationality=nationality;
}

//Destructor for Tournament Member
TournamentMember::~TournamentMember(){
    cout<<"\n Destructor for TournamentMember \n"<<endl;
}


string TournamentMember::location = "Nepal";
//Service Methods

void TournamentMember::print(){
    //print the details 
    cout<<"---------------------------------------"<<endl;
    cout<<"First Name    : "<<this->fname<<endl;
    cout<<"Last  Name    : "<<this->lname<<endl;
    cout<<"Date Of Birth : "<<this->dob<<endl;
    cout<<"Age           : "<<this->age<<endl;
    cout<<"Location      : "<<location<<endl;
    cout<<"Nationality   : "<<this->nationality<<endl;
    cout<<"---------------------------------------"<<endl;
}






