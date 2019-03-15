/*
CH08-320142
Problem 3.1 cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include "City.h"
using namespace std;

int main (int argc,char** argv){
    
    City bremen("Bremen"),hamburg("Hamburg"),berlin("Berlin");
    
    //setting properties of bremen object
    bremen.setLocation("Germany");
    bremen.setNumOfCitizens(7071);
    bremen.setPoi("Bremen Central");
    
    //setting properties of hamburg object
    hamburg.setLocation("Germany");
    hamburg.setNumOfCitizens(7142);
    hamburg.setPoi("Rathause");
    
    //setting properties of berlin object
    berlin.setLocation("Germany");
    berlin.setNumOfCitizens(7006);
    berlin.setPoi("Brandenburg Gate");

    //printing properties of objects
    bremen.print();
    hamburg.print();
    berlin.print();
    
    }