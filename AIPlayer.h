/*
 * AIPlayer.h
 *
 *  Created on: Dec 7, 2016
 *      Author: student
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"

class AIPlayer : public Player
{
public:
   /**
    * Constructor
    */
  AIPlayer(std::string);

   /**
    * Destructor
    */
   virtual ~AIPlayer();

   /**
    * Play a card. If the player receives a joker then this player is going first
    */
   const Card playCard(const Card opponentCard);

   /**
    * Receive the cards played from the previous round and save them in the "memory"
    * of a computer player to be used for making decision on what card should be
    * played next.
    */
   void cardsPlayed(const Card, const Card);

   /**
    * Function calculates the probability of winning for the given card
    */
   double calcProbability(Card c) const;

   /**
    * Function determines which card in hand has a higher probability of winning;
    * used when a player goes first
    */
   const Card defCardHighestProb() const;

   /**
    * Function determines the smallest card in hand;
    * Used when a player goes second and it has no cards to beat the opponent's card,
    * so it just gives up the card of a smallest value
    */
   const Card defCardSmallest() const;

   /**
    * Function determines a card to play; used when a player goes second and it has
    * some cards in hand that can beat the opponent's card, so it chooses the smallest
    * card among cards that can beat the opponent's card
    */
   const Card defCardBigger(const Card);

   /**
    * Function finds the potential number of cards that are smaller by value than
    * a given card;
    */
   int findNumOfCardsSmaller(Card c) const;

   /**
    * Function determines which cards should be excluded from calculation (cards that
    * were played and cards in hand)
    */
   int findNumOfCardsToExclude(Card c) const;

   /**
    * Function gets index of card in vector hand; used to delete that card from hand
    * after it was played
    */
   int getIndexOfCard(Card c) const;

   /**
    * Function shows cards in hand of a player; not used in the game but may be used
    * for debugging purposes
    */
   void displayCards() const;

   /**
    * Function determines whether a player has any card to beat the opponent's card
    */
   bool hasAnythingToPlay(const Card opponentCard) const;
private:
   //a player's "memory" that keeps track of all cards played
   std::vector<Card> playedCards;
};


#endif /* AIPLAYER_H_ */
