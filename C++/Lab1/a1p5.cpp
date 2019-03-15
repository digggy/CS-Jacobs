/*
CH08-320142
Problem 1.5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include<iostream>
#include<string>
using namespace std;

int main (int argc,char** argv){
    string str_a="";
    char a;
    bool state=true;
    while (state==true){
        cin>>a;
        if (a=='q'){
            state = false;
        }else if (a=='\n'|| a=='\t'||a==' '){
            //(nothing) do not add in str_a 
        }else{
            str_a+=a;
        }
    }
    cout << str_a<<endl;
    return 0;
}