/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include <vector>
#include "Card.h"

#ifndef _HAND_H
#define _HAND_H
using namespace std;

class Hand
{
public:
  Hand();

  virtual ~Hand();

  //adds a card to the hand
  void Add(Card *pCard);

  //clears hand of all cards
  void Clear();

  //gets hand total value, intelligently treats aces as 1 or 11
  int GetTotal() const;

protected:
  vector<Card *> m_Cards;
};
#endif