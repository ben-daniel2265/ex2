#ifndef EX2_GAME_SOURCE
#define EX2_GAME_SOURCE

#include "Mtmchkin.h"
#include <iostream>

Card* copyCards(const Card* originalDeck, int numOfCards)
{
    Card* newDeck = new Card[numOfCards];

    for(int i = 0;i < numOfCards;i++){
        newDeck[i] = originalDeck[i];
    }

    return newDeck;
}

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_player(Player(playerName))
{
    this->m_cardDeck = copyCards(cardsArray, numOfCards);
    this->m_numOfCards = numOfCards;
    this->m_currentCard = 0;
    this->m_gameStatus = GameStatus::MidGame;
    
}

Mtmchkin::Mtmchkin(const Mtmchkin& mtmchkin) : m_player(Player(mtmchkin.m_player))
{
    this->m_cardDeck = copyCards(mtmchkin.m_cardDeck, mtmchkin.m_numOfCards);
    this->m_numOfCards = mtmchkin.m_numOfCards;
    this->m_currentCard = mtmchkin.m_currentCard;
    this->m_gameStatus = mtmchkin.m_gameStatus;
}

Mtmchkin::~Mtmchkin()
{
    delete[] this->m_cardDeck;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& mtmchkin)
{
    if(&mtmchkin == this){
        return *this;
    }

    delete[] this->m_cardDeck;
    this->m_player = mtmchkin.m_player;
    this->m_cardDeck = copyCards(mtmchkin.m_cardDeck, mtmchkin.m_numOfCards);
    this->m_numOfCards = mtmchkin.m_numOfCards;
    this->m_currentCard = mtmchkin.m_currentCard;
    this->m_gameStatus = mtmchkin.m_gameStatus;

    return *this;
}


void Mtmchkin::playNextCard()
{
    Card card = Card(this->m_cardDeck[this->m_currentCard]);
    this->m_currentCard++;
    if(this->m_currentCard >= this->m_numOfCards){
        this->m_currentCard = 0;
    }

    card.printInfo();

    card.applyEncounter(this->m_player);
    this->m_player.printInfo();

    if(this->m_player.isKnockedOut()){
        this->m_gameStatus = GameStatus::Loss;
    }
    else if(this->m_player.getLevel() >= 10){
        this->m_gameStatus = GameStatus::Win;
    }
}


bool Mtmchkin::isOver()
{
    return this->m_gameStatus != GameStatus::MidGame;
}


GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}



#endif //EX2_GAME_SOURCE