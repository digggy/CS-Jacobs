/*
CH08-320143
a4p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "Access.h"

// Activate the code
void Access::activate(unsigned long code)
{
    this->passCodes.insert(code);
};

//Deactivate the code
void Access::deactivate(unsigned long code)
{
    this->passCodes.erase(code);
};

//Check if the element is in the list
bool Access::isactive(unsigned long code) const
{
    return this->passCodes.find(code) != this->passCodes.end();
};