/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de

*/
#include "Hand.h"

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card *pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card *>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    int total = 0;
    vector<Card *>::const_iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        Card *temp = *iter;
        int ace = 0;

        if (temp->GetValue() == 1)
        {
            ace++;
        }
        else
        {
            total += temp->GetValue();
        }
        // Case when the total is less than equal to 10
        // Then we have Ace's value as 11

        for (int i = 0; i < ace; i++)
        {
            if (total <= 10)
            {
                total += 11;
            }
            else
            {
                total += 1;
            }
        }
    }
    return total;
}
