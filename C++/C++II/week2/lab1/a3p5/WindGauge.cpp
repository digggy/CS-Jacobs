/*
CH08-320143
a3p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include "WindGauge.h"
using namespace std;

//Constructor
WindGauge::WindGauge(int period)
{
    this->period = period;
}

//Adding the current speed
void WindGauge::currentWindSpeed(int speed)
{
    if ((int)this->A.size() == this->period)
    {
        this->A.pop_back();
    }
    this->A.push_front(speed);
}

//Print the current
void WindGauge::dump()
{
    //Printing the values for different conditions
    cout << "The lowest is : ";
    cout << this->lowest() << endl;
    cout << "The average is : ";
    cout << this->average() << endl;
    cout << "The highest is : ";
    cout << this->highest() << endl;
}

//Method to find the highest, iterating through the elements
int WindGauge::highest() const
{
    int highest;
    highest = *(this->A.begin());
    deque<int>::const_iterator pos;
    for (pos = this->A.begin(); pos != this->A.end(); pos++)
    {
        if (*pos > highest)
        {
            highest = *pos;
        }
    }
    return highest;
}
//Method to find the lowest, iterating through the elements

int WindGauge::lowest() const
{
    int lowest;
    lowest = *(this->A.begin());
    deque<int>::const_iterator pos;
    for (pos = this->A.begin(); pos != this->A.end(); pos++)
    {
        if (*pos < lowest)
        {
            lowest = *pos;
        }
    }
    return lowest;
}

//Method to find the Average iterating through the elements
int WindGauge::average() const
{
    int avg = 0;
    deque<int>::const_iterator pos;
    for (pos = this->A.begin(); pos != this->A.end(); pos++)
    {
        avg += *pos;
    }
    avg = (int)avg / this->A.size();
    return avg;
}