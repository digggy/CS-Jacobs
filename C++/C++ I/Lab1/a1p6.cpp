/*
CH08-320142
Problem 1.6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

int main (int argc,char** argv){
    string user_name;
    int number;
    //initialising the seed for rand()
    srand(static_cast<unsigned int >(time(0)));

    int randNum=((rand() % 100) +1);  
    cout << "Input your name : ";
    getline(cin,user_name);
    cout << "Guess the Number : ";
    cin >> number; 
    
    //Guess until the guess is right 
    while(number != randNum){
        if (number>randNum){
	   cout<<"Your Number is greater" << endl;
	  }else{
	   cout<<"Your Number is lesser" << endl;    
        }
        cout << "Guess the Number : ";
        cin >> number;
    } 
    
    cout<<"Congratulations your guess "<< number<< " is correct. "<<endl;
    return 0;   

}
