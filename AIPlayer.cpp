/*
 * AIPlayer.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: dkhelemendyk
 */

#include <vector>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "AIPlayer.h"
/**
 * Constructor
 * Creates a player with the name provided as a parameter
 */
AIPlayer::AIPlayer(std::string name)
 :Player(name)
 {
 }

/**
 * Destructor
 */
AIPlayer::~AIPlayer()
{
}

/**
 * Play a card. If a player receives a joker then this player is going first
 * If another card - goes second. If a player goes first, a function chooses a card
 * to play based on the highest probability of winning of the card; if a player goes
 * second, a function checks whether a player has any card that can beat the opponent's
 * card, if yes - chooses the smallest card enough to beat the opponent's card, if
 * no - gives up the smallest card in hand
 */
const Card AIPlayer::playCard(const Card opponentCard)
{
  Card cardToPlay;
  //displayCards(); //uncomment if you'd like to see how cards are being chosen
  bool isFirst = opponentCard.isJoker() ? true : false;
  if (isFirst)
    {
      std::cout << name << " goes first. ";
      //choose a card with the highest probability of winning
      cardToPlay = defCardHighestProb();
    }
  else
    {
      std::cout << name << " goes second. ";
      if (hasAnythingToPlay(opponentCard))
	{
	  //get a smallest card among those that can beat the opponent's card and
	  //save bigger cards for later
	  cardToPlay = defCardBigger(opponentCard);
	}
      else
	{
	  //give up the smallest card when there is no chance to beat the opponent's
	  //card anyway
          cardToPlay = defCardSmallest();
	}
    }

  std::cout << name << " plays " << cardToPlay << std::endl;
  int cardNumber = getIndexOfCard(cardToPlay);  //get index of a played card
  hand.erase(hand.begin() + cardNumber); //delete card from hand
  return cardToPlay;
}

/**
 * Shows the cards in the player's hand (could be 1 - 3);
 * used for debugging purposes
 */
void AIPlayer::displayCards() const
{
  std::cout << name << "'s hand: " << std::endl;
  if (!hasCards())
    {
      std::cout << "empty." << std::endl;
      return;
    }
  for (Card c : hand)
    {
      std::cout << c << std::endl;
    }
}

/**
 * Gets cards played and saves them into a player's "memory"
 */
void AIPlayer::cardsPlayed(const Card card1, const Card card2) {
  playedCards.push_back(card1);
  playedCards.push_back(card2);
}

/**
 * Function determines whether a player has any card to beat the opponent's card
 */
bool AIPlayer::hasAnythingToPlay(const Card opponentCard) const
{
  bool haveSomethingToPlay = false;
  for (Card c : hand)
    {
      if (opponentCard < c) haveSomethingToPlay = true;
    }
  return haveSomethingToPlay;
}

/**
 * Function determines which card in hand has a higher probability of winning;
 * used when a player goes first
 */
const Card AIPlayer::defCardHighestProb() const
{
  Card cardToPlay = hand[0];;
  double maxProbOfWin = calcProbability(hand[0]);
  for (Card c : hand)
    {
      double probOfWin = calcProbability(c);
      if ( probOfWin > maxProbOfWin)
	{
	  maxProbOfWin = probOfWin;
	  cardToPlay = c;
	}
      if (probOfWin == maxProbOfWin)
	{
	  if (c < cardToPlay)
	    {
	      cardToPlay = c;
	    }
	}
    }
  return cardToPlay;
}

/**
 * Function determines the smallest card in hand;
 * Used when a player goes second and it has no cards to beat the opponent's card,
 * so it just gives up the card of a smallest value
 */
const Card AIPlayer::defCardSmallest() const
{
  Card smallest = hand[0];
  for (Card c : hand)
    {
      if (c < smallest) smallest = c;
    }
  return smallest;
}

/**
 * Function determines a card to play; used when a player goes second and it has
 * some cards in hand that can beat the opponent's card, so it chooses the smallest
 * card among cards that can beat the opponent's card
 */
const Card AIPlayer::defCardBigger(const Card opponentCard)
{
  std::sort(hand.begin(), hand.end());
  Card cardToPlay = hand[0];
  for (Card c : hand)
    {
      if (opponentCard < c)
	{
	  cardToPlay = c;
	  break;
	}
    }
  return cardToPlay;
}

/**
 * Function gets index of card in vector hand; used to delete that card from hand
 * after it was played
 */
int AIPlayer::getIndexOfCard(Card c) const
{
  unsigned int index;
  for (unsigned int i = 0; i < hand.size(); ++i)
    {
      if (hand[i] == c)
	{
    	  index = i;
  	  break;
  	}
    }
  return index;
}

/**
 * Function calculates the probability of winning for the given card
 */
double AIPlayer::calcProbability(Card c) const
{
  int numOfCardsSmaller = findNumOfCardsSmaller(c);
  int numOfCardsToExclude = findNumOfCardsToExclude(c);
  int cardsLeftInDeck = 52 - playedCards.size();
  double probOfWin = (double)(numOfCardsSmaller * 4 - numOfCardsToExclude)/cardsLeftInDeck;
  return probOfWin;
}

/**
 * Function finds the potential number of cards that are smaller by value than
 * a given card;
 */
int AIPlayer::findNumOfCardsSmaller(Card c) const
{
  return c.getRank() - 1;
}

/**
 * Function determines which cards should be excluded from calculation (cards that
 * were played and cards in hand)
 */
int AIPlayer::findNumOfCardsToExclude(Card c) const
{
  int numToExclude = 0;
  for (Card card : playedCards)
    {
      if (card < c) ++numToExclude;
    }
  for (Card card : hand)
    {
      if (card < c) ++numToExclude;
    }
  return numToExclude;
}





