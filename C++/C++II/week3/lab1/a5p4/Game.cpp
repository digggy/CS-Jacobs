
#include "Game.h"
Game::Game(const vector<string> &names)
{
    //create a vector of players from a vector of names
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        m_Players.push_back(Player(*pName));
    }

    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{
}

void Game::Play()
{
    //deal initial 2 cards to everyone
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    //hide house's first card
    m_House.FlipFirstCard();

    //display everyone's hand
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << m_House << endl;

    //deal additional cards to players
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AdditionalCards(*pPlayer);
    }

    //reveal house's first card
    m_House.FlipFirstCard();
    cout << endl
         << m_House;

    //deal additional cards to house
    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        //everyone still playing wins
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        //compare each player still playing to house
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }
    }

    //remove everyone's cards
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    m_House.Clear();
}

//function prototypes
ostream &operator<<(ostream &os, const Card &aCard);
ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);
