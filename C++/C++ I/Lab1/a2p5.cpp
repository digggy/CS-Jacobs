/*
CH08-320142
Problem 2.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s);

int main (int argc,char** argv){
    string word;
   
    while(word !="stop"){
        cout<<"Enter a word"<<endl;
        cin>>word;
        if (word !="stop"){       
            if (isPalindrome(word)==true){ //calling the fuction isPalindrome
                cout<<" >> It is a palindrome"<<endl;
            }else{
                cout<<" >> It is not a palindrome"<<endl;
            }
        }
    }
    return 0;
}


bool isPalindrome(string s){
    string reverse;
    for (unsigned int i =0 ; i<s.length();i++){
        reverse=s[i]+reverse;
    }
    //checking if the reverse string is same as the original string and returning accordingly
    return (reverse==s)?true:false; 
}
