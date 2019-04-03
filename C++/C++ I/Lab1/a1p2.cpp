/*
CH08-320142
Problem 1.2.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

int main (int argc, char** argv){
    int nr;
    float val;
    string s;
    
    cin >> nr;
    cin >> val;
    cin.get();
    getline(cin,s);

    for (int i=0;i<nr;i++){
        cout<< val <<" "<< s<<endl;
    }
    return 0;
}
    
