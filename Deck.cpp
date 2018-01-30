/*
 * Deck.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: dkhelemendyk
 */

#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>
#include "Deck.h"
using namespace std;

/**
 * Default constructor
 * Creates a full deck of cards (52 cards), cards are shuffled then
 */
Deck::Deck()
{
  nextCard = MaxCards;
  for (unsigned int i = 1; i <= MaxCards/4; ++i)
    {
      Card s {Card::Spades, Card::Rank(i)};
      cardDeck.push_back(s);
      Card h {Card::Hearts, Card::Rank(i)};
      cardDeck.push_back(h);
      Card d {Card::Diamonds, Card::Rank(i)};
      cardDeck.push_back(d);
      Card c {Card::Clubs, Card::Rank(i)};
      cardDeck.push_back(c);
    }
  this->shuffle();
}

/**
 * Destructor
 */
Deck::~Deck()
{
}

/**
 * Shuffles the deck of cards
 * @param none
 * @return none
 */
void Deck::shuffle()
{
  // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
  nextCard = MaxCards;
}

/**
 * Checks whether the deck is empty
 * @param none
 * @return true if the deck is empty, false if not
 */
bool Deck::isEmpty() const
{
  return nextCard <= 0;
}

/**
 * Draws a card from our deck
 * @param none
 * @return one card
 */
const Card Deck::draw()
{
  if (isEmpty())
    throw std::out_of_range("The deck is empty!");
  return cardDeck[--nextCard];
}
