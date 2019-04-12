/*
CH08-320143
a4p6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "Access.h"

// Activate the code
void Access::activate(unsigned long code, unsigned int level)
{
    this->passCodes[code] = level;
};

//Deactivate the code
void Access::deactivate(unsigned long code)
{
    this->passCodes.erase(code);
};

//Change level
void Access::change(unsigned long code, unsigned long level)
{
    this->passCodes.erase(code);
    this->passCodes[code] = level;
}

//Check if the element is in the list and matches the level required
bool Access::isactive(unsigned long code, unsigned int level) const
{
    if (this->passCodes.find(code) != this->passCodes.end())
    {
        if (this->passCodes.find(code)->second >= level)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
};