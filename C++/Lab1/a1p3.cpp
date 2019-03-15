/*
CH08-320142
Problem 1.3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

//function that determines the sign to be returned.
int sign(int x){

    if (x>0){
        return 1; 
    }else if (x<0){
        return -1;
    }else{
        return 0; // if x == 0 then return 0
    }
}

int main (int argc, char** argv){
    int x=-10;
    cout <<"The sign value of "<< x << " is "<< sign(x)<<endl;
    return 0;
}
    
