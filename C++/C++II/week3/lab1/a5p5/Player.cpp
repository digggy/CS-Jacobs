/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include "Player.h"

Player::Player(const string &name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting() const
{
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
    cout << m_Name << " wins.\n";
}

void Player::Lose() const
{
    cout << m_Name << " loses.\n";
}

void Player::Push() const
{
    cout << m_Name << " pushes.\n";
}
