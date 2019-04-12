/*
CH08-320143
a3p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "WindGauge.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    //Creating a sample object
    WindGauge sample;

    cout << "Welcome to the Wind Station \n\n";
    cout << "Initial Wind Speeds\n";
    //Adding the wind speeds
    sample.currentWindSpeed(14);
    sample.currentWindSpeed(16);
    sample.currentWindSpeed(13);
    sample.currentWindSpeed(15);
    sample.currentWindSpeed(15);

    //Printing the current statuses
    sample.dump();

    //Adding more wind speeds
    sample.currentWindSpeed(15);
    sample.currentWindSpeed(17);
    sample.currentWindSpeed(17);
    sample.currentWindSpeed(16);
    sample.currentWindSpeed(20);
    sample.currentWindSpeed(15);
    sample.currentWindSpeed(16);
    sample.currentWindSpeed(20);

    cout << "\nAfter adding more Wind Speeds\n";
    sample.dump();

    return 0;
}
