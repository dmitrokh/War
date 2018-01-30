/*
 * Card.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: dkhelemendyk
 */
#include "Card.h"
using namespace std;

/**
 * Default constructor; creates a Joker card, suit can be disregarded
 */
Card::Card()
{
  cardSuit = Spades;
  cardRank = Joker;
}

/**
 * Constructor with arguments
 * Takes acceptable values from enums Suit and Rank as parameters
 */
Card::Card(Suit s, Rank r)
:cardSuit{s}, cardRank{r}
{
}

/**
  * Overrides << operator for objects of type Card
  * @param output stream, Card object
  * @return output stream in form of "Rank of Suit"
  */
std::ostream& operator <<(std::ostream& os, const Card& c)
{
  os << rankNames[c.cardRank] << " of " << suitNames[c.cardSuit];
  return os;
}

/**
  * Overrides the comparison operator "==" for objects of type Card
  * @param two objects of type Card to compare
  * @return boolean result of comparison
  */
bool operator ==(const Card &lhs, const Card &rhs)
{
  return lhs.cardRank == rhs.cardRank && lhs.cardSuit == rhs.cardSuit;
}

/**
  * Overrides the comparison operator "<" for objects of type Card
  * @param two objects of type Card to compare
  * @return boolean result of comparison
  */
bool operator <(const Card &lhs, const Card &rhs)
{
  if (lhs.cardRank == 0)
    return false;
  if (rhs.cardRank == 0)
    return true;
  return lhs.cardRank < rhs.cardRank;
}

const int Card::getRank() const
{
  return cardRank;
}
