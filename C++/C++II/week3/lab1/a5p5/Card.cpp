/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include "Card.h"

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{
}
int Card::GetValue() const
{
    int value;
    // to be filled with content
    value = (this->m_Rank > 10) ? 10 : this->m_Rank;
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}
