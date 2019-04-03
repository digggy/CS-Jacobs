/*
CH08-320142
Problem 1.4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

int mycount(int a,int b);
int mycount(string a,char b);

int main (int argc,char** argv){

    cout<<mycount(7,3)<<endl;
    cout<<mycount("this is a string", 'i')<<endl;
    cout<<mycount("apple",'z')<<endl;
} 
  
//function that determines the difference between the first and the second number
int mycount(int a, int b){
    return a-b;
}

//funtion that counts number of a given character in the given string
int mycount(string a,char b){
    int count=0;
    for (unsigned int i=0; i< a.length();i++){
        if (a[i]==b){
            count+=1;
        }
    }
    if (count==0){
        //returns -1 if there is no occurance of that character
        return -1;
    }else{
        return count;
    }
}
  

