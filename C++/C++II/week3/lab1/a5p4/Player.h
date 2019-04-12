/*
CH08-320143
a5p1.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/
#include "GenericPlayer.h"
#ifndef _PLAYER_H
#define _PLAYER_H

class Player : public GenericPlayer
{
public:
  Player(const string &name = "");

  virtual ~Player();

  //returns whether or not the player wants another hit
  virtual bool IsHitting() const;

  //announces that the player wins
  void Win() const;

  //announces that the player loses
  void Lose() const;

  //announces that the player pushes
  void Push() const;
};
#endif