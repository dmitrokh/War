/*
 * TerminalPlayer.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: dkhelemendyk
 */

#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include "TerminalPlayer.h"
/**
 * Constructor
 * Creates a player with the name provided as a parameter
 */
TerminalPlayer::TerminalPlayer(std::string name, int t)
 :AIPlayer(name)
 {
   type = t;
 }

/**
 * Destructor
 */
TerminalPlayer::~TerminalPlayer()
{
}

/**
 * Play a card. If a player receives a joker then this player is going first
 * If another card - goes second.
 * A function displays cards in hand and allows to choose a card to play,
 * the card played is being deleted from hand
 */
const Card TerminalPlayer::playCard(const Card opponentCard)
{
  Card cardToPlay;
  bool isFirst = opponentCard.isJoker() ? true : false;
  if (isFirst)
    {
      std::cout << name << " goes first. ";
    }
  else
    {
      std::cout << name << " goes second. ";
    }
  if (type == 1) //human vs computer game mode
    {
      cardToPlay = playTypeOneGame();
    }
  else //computer vs computer game mode
    {
      cardToPlay = playTypeTwoGame(isFirst, opponentCard);
    }
  return cardToPlay;
}

const Card TerminalPlayer::playTypeOneGame()
{
  Card card;
  unsigned int cardNumber;
  displayCards();
  std::cout << "Choose card to play " <<
            "(enter number 1, 2, or 3 for a card in hand from top to bottom): ";
  while (true)
  {
    std::cin >> cardNumber;
    if (!std::cin || cardNumber < 1 || cardNumber > hand.size())
    {
      std::cout << "Enter a valid number for cards in hand: ";
      std::cin.clear();
      //use ignore() to discard any literals met after input was read into cin; in case if a
      //user enters a floating point number instead of an integer
      std::cin.ignore(100, '\n');
    }
    else
    {
      std::cin.ignore(100, '\n');
      break;
    }
  }
  card = hand[cardNumber - 1];
  std::cout << name << " plays " << card << std::endl;
  hand.erase(hand.begin() + (cardNumber - 1));
  return card;
}

const Card TerminalPlayer::playTypeTwoGame(bool isF, Card opCard)
{
  Card card;
  //displayCards(); //uncomment if you'd like to see how cards are being chosen
  if (isF)
    {
      //choose a card with the highest probability of winning
      card = defCardHighestProb();
    }
  else
    {
      if (hasAnythingToPlay(opCard))
  	{
  	  //get a smallest card among those that can beat the opponent's card and
  	  //save bigger cards for later
  	  card = defCardBigger(opCard);
  	}
      else
  	{
  	  //give up the smallest card when there is no chance to beat the opponent's
  	  //card anyway
          card = defCardSmallest();
  	}
    }
  std::cout << name << " plays " << card << std::endl;
  int cardNumber = getIndexOfCard(card);  //get index of a played card
  hand.erase(hand.begin() + cardNumber); //delete card from hand
  return card;
}

/**
 * Shows the cards in the player's hand (could be 1 - 3)
 */
/*void TerminalPlayer::displayCards() const
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
}*/

/**
 * Receive the cards played from the previous round and save them in the "memory"
 * of a computer player to be used for making decision on what card should be
 * played next.
 */
/*void TerminalPlayer::cardsPlayed(const Card card1, const Card card2)
{
  playedCards.push_back(card1);
  playedCards.push_back(card2);
}*/

/**
 * Function determines whether a player has any card to beat the opponent's card
 */
/*bool TerminalPlayer::hasAnythingToPlay(const Card opponentCard) const
{
  bool haveSomethingToPlay = false;
  for (Card c : hand)
    {
      if (opponentCard < c) haveSomethingToPlay = true;
    }
  return haveSomethingToPlay;
}*/

/**
 * Function determines which card in hand has a higher probability of winning;
 * used when a player goes first
 */
/*const Card TerminalPlayer::defCardHighestProb() const
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
}*/

/**
 * Function determines the smallest card in hand;
 * Used when a player goes second and it has no cards to beat the opponent's card,
 * so it just gives up the card of a smallest value
 */
/*const Card TerminalPlayer::defCardSmallest() const
{
  Card smallest = hand[0];
  for (Card c : hand)
    {
      if (c < smallest) smallest = c;
    }
  return smallest;
}*/

/**
 * Function determines a card to play; used when a player goes second and it has
 * some cards in hand that can beat the opponent's card, so it chooses the smallest
 * card among cards that can beat the opponent's card
 */
/*const Card TerminalPlayer::defCardBigger(const Card opponentCard)
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
}*/

/**
 * Function gets index of card in vector hand; used to delete that card from hand
 * after it was played
 */
/*int TerminalPlayer::getIndexOfCard(Card c) const
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
}*/

/**
 * Function calculates the probability of winning for the given card
 */
/*double TerminalPlayer::calcProbability(Card c) const
{
  int numOfCardsSmaller = findNumOfCardsSmaller(c);
  int numOfCardsToExclude = findNumOfCardsToExclude(c);
  int cardsLeftInDeck = 52 - playedCards.size();
  double probOfWin = (double)(numOfCardsSmaller * 4 - numOfCardsToExclude)/cardsLeftInDeck;
  return probOfWin;
}*/

/**
 * Function finds the potential number of cards that are smaller by value than
 * a given card;
 */
/*int TerminalPlayer::findNumOfCardsSmaller(Card c) const
{
  return c.getRank() - 1;
}*/

/**
 * Function determines which cards should be excluded from calculation (cards that
 * were played and cards in hand)
 */
/*int TerminalPlayer::findNumOfCardsToExclude(Card c) const
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
}*/



