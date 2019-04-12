/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include <iostream>
using namespace std;

#ifndef _CARD_H
#define _CARD_H

class Card
{
public:
  enum rank
  {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
  };
  enum suit
  {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
  };

  //overloading << operator so can send Card object to standard output
  friend ostream &operator<<(ostream &os, const Card &aCard);

  Card(rank r = ACE, suit s = SPADES, bool ifu = true);

  //returns the value of a card, 1 - 11
  int GetValue() const;

  //flips a card; if face up, becomes face down and vice versa
  void Flip();

private:
  rank m_Rank;
  suit m_Suit;
  bool m_IsFaceUp;
};
#endif