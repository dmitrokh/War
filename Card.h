/*
 * Card.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

/**
 * String constants for the suits
 */
static const std::string suitNames[] =
		{ "Spades", "Hearts", "Diamonds", "Clubs" };

/**
 * String constants for the rank
 */
static const std::string rankNames[] = { "Joker", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
		"Ace" };

/**
 * Card class to represent a single playing card
 */
class Card {
public:
	/**
	 * Suit enumerations
	 */
	enum Suit {
		Spades = 0, Hearts, Diamonds, Clubs
	};

	/**
	 * Rank enumerations ordered by value for game of war
	 */
	enum Rank {
		Joker = 0,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};

	/**
	 * Constructor
	 *
	 * @param s
	 * @param r
	 */
	Card(Suit, Rank);

	/**
	 * Constructor. This empty constructor will create a joker card.
	 * The joker card is a special card given to the player going first.
	 */
	Card();

	/**
	 * Destructor
	 */
	virtual ~Card() {
	}

	/**
	 * Return true if this card is a joker
	 */
	bool isJoker() const {
		return (cardRank == Joker);
	}

	/**
	 * Output the card to an output stream as "rank of suit"
	 */
	friend std::ostream& operator <<(std::ostream&, const Card&);

	/**
	 * Compare operators. For the game of war we only care about the rank
	 */
	friend bool operator ==(const Card &lhs, const Card &rhs);
	friend bool operator <(const Card &lhs, const Card &rhs);

	const int getRank() const;
private:
	Suit cardSuit;
	Rank cardRank;
};

#endif /* CARD_H_ */
