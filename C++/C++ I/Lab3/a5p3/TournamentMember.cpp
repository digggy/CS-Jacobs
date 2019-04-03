/*
CH08-320142
Problem 5.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include "TournamentMember.h"

using namespace std;

//Constructor for Tournament Member
TournamentMember::TournamentMember(const char fname[31],const char lname[32],
const char dob[11],int age,string nationality){

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
    cout<<"\nDestructor for TournamentMember \n"<<endl;
}


string TournamentMember::location = "Nepal";
//Service Methods

void TournamentMember::print(){
    //print the details 
    
    cout<<"\nFirst Name      : "<<this->fname<<endl;
    cout<<"Last  Name      : "<<this->lname<<endl;
    cout<<"Date Of Birth   : "<<this->dob<<endl;
    cout<<"Age             : "<<this->age<<endl;
    cout<<"Location        : "<<location<<endl;
    cout<<"Nationality     : "<<this->nationality<<endl;
    
}

Player::Player(const char fname[31],const char lname[32],const char dob[11],int age,
string nationality,int number,std::string position,int goal,string foot) 
: TournamentMember(fname,lname,dob,age,nationality){
   
    cout<<"Constructor Player \n\n";

    this->number=number;
    this->position=position;
    this->goal=goal;
    this->foot=foot;
}

Player::Player(Player& src) :
    TournamentMember(src.getFname(),src.getLname(),src.getDob(),src.getAge(),
    src.getNationality())
{
    this->number=src.getNumber();
    this->position=src.getPosition();
    this->goal=src.getGoal();
    this->foot=src.getFoot();
}

Player::~Player(){
    cout<<"\nDestructor Player"<<endl;
}

//Application Methods
void Player::print(){
   cout<<"---------------------------------"<<endl<<endl;
    TournamentMember::print();
    cout<<"Player Number   : " << getNumber() << endl;
    cout<<"Player Position : " << getPosition()<<endl;
    cout<<"Player Goal     : " << getGoal()<<endl;
    cout<<"Player Foot     : " << getFoot()<<endl; 
   cout<<"---------------------------------"<<endl<<endl;
}
//Increase Goal
void Player::addGoal(){
    goal=+1;
}



