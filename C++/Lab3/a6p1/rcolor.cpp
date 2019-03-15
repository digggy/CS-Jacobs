/*
CH08-320142
Problem 6.1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string rcolor(string colors[]);

int main(){
    int count = 0;
    string colors [4]={"RED","YELLOW","BLUE","GREEN"};
    
    // init random number generator

    srand(static_cast<unsigned int>(time(0)));
    while (count < 10) {
        cout << (count+1) << ": " << rcolor(colors)<< endl;
        count++;
    }
    return 0;
}


//function to choose the color randomly 
string rcolor (string colors[]){
    int randomNumber;
    int item;
    
    //generating randomNumber
    randomNumber = rand();
    item = (randomNumber % 4);

    //returning a color in random index == item     
    return colors[item];
}
