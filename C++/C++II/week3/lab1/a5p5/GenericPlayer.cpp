/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string &name) : m_Name(name)
{
}

GenericPlayer::~GenericPlayer()
{
}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    cout << m_Name << " busts.\n";
}
