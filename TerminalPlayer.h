/*
 * TerminalPlayer.h
 *
 *  Created on: Nov 21, 2016
 *      Author: dkhelemendyk
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include "AIPlayer.h"

class TerminalPlayer : public AIPlayer
{
public:
   /**
    * Constructor
    */
   TerminalPlayer(std::string, int);

   /**
    * Destructor
    */
   virtual ~TerminalPlayer();

   /**
    * Play a card. If the player receives a joker then this player is going first
    */
   const Card playCard(const Card opponentCard);

   /**
    * Shows the cards in the player's hand (could be 1 - 3)
    */
   //void displayCards() const;

   /**
    * Receive the cards played from the previous round and save them in the "memory"
    * of a computer player to be used for making decision on what card should be
    * played next.
    */
   //void cardsPlayed(const Card, const Card);

   /**
    * A human player vs  computer player (AI) game
    */
   const Card playTypeOneGame();

   /**
    * A computer vs computer player game (AI players)
    */
   const Card playTypeTwoGame(bool, Card);

   /**
    * Function calculates the probability of winning for the given card
    */
   //double calcProbability(Card c) const;

   /**
    * Function determines which card in hand has a higher probability of winning;
    * used when a player goes first
    */
   //const Card defCardHighestProb() const;

   /**
    * Function determines the smallest card in hand;
    * Used when a player goes second and it has no cards to beat the opponent's card,
    * so it just gives up the card of a smallest value
    */
   //const Card defCardSmallest() const;

   /**
    * Function determines a card to play; used when a player goes second and it has
    * some cards in hand that can beat the opponent's card, so it chooses the smallest
    * card among cards that can beat the opponent's card
    */
   //const Card defCardBigger(const Card);

   /**
    * Function finds the potential number of cards that are smaller by value than
    * a given card;
    */
   //int findNumOfCardsSmaller(Card c) const;

   /**
    * Function determines which cards should be excluded from calculation (cards that
    * were played and cards in hand)
    */
   //int findNumOfCardsToExclude(Card c) const;

   /**
    * Function gets index of card in vector hand; used to delete that card from hand
    * after it was played
    */
   //int getIndexOfCard(Card c) const;

   /**
    * Function determines whether a player has any card to beat the opponent's card
    */
   //bool hasAnythingToPlay(const Card opponentCard) const;

private:
   int type;
   //std::vector<Card> playedCards;
};

#endif /* TERMINALPLAYER_H_ */
