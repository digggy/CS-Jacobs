#include <vector>
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <ctime>

#ifndef _GAME_H
#define _GAME_H
using namespace std;

class Game
{
public:
  Game(const vector<string> &names);

  ~Game();

  //plays the game of blackjack
  void Play();

private:
  Deck m_Deck;
  House m_House;
  vector<Player> m_Players;
};
#endif