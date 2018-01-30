/*
 * main.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: dkhelemendyk
 */

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"
#include "TerminalPlayer.h"
#include "AIPlayer.h"

using namespace std;

int main()
{
  int gameType;
  //choose a type of a game
  cout << "Choose game mode: Enter 1 for human vs computer "
       << "or any other number for computer vs computer" << endl;
  cout << "Your choice: ";
  while (true) {
    cin >> gameType;
    if (!cin || gameType < 1) {
      cout << "Enter a valid number: ";
      cin.clear();
      //use ignore() to discard any literals met after input was read into cin; in case if a
      //user enters a floating point number instead of an integer
      cin.ignore(100, '\n');
    }
    else {
      cin.ignore(100, '\n');
      break;
    }
  }
  cout << endl;

  //create a new deck of cards
  cout << "Create a new deck of cards..." << endl;
  Deck d1{};

  //create first player
  cout << "Create first player (either human or computer)..." << endl;
  TerminalPlayer player1 {"Player1", gameType};

  //create second player
  cout << "Create second player (computer only)..." << endl;
  AIPlayer player2 {"Player2"};

  //deal 3 cards to each player
  cout << "Deal cards to players..." << endl;
  for (unsigned int i = 1; i <= 3; ++i)
    {
      player1.receiveCard(d1.draw());
      player2.receiveCard(d1.draw());
    }

  //create a flag to keep track of who goes first, by default,
  //player who was created first (either a human or a computer), goes first
  bool first = true;

  //randomly pick who will play first, if it's a number 1 randomly chosen,
  //then player created first goes first still, if 2 - player created second
  cout << "Randomly choose a player who will go first..." << endl;
  srand (time(NULL)); //initialize random seed
  int choice = rand() % 2 + 1; //generate random number between 1 and 2
  if (choice == 2)
    {
      first = false;
    }
  cout << "________________________GAME BEGINS__________________________" << endl << endl;

  int i = 1;
  while (player1.hasCards() && player2.hasCards())
    {
      cout << "Deal #" << i++ << endl;

      Card c1, c2;
      if (first)
        {
          c1 = player1.playCard(Card{Card::Spades, Card::Joker});
          c2 = player2.playCard(c1);
          if (c2 < c1) //if the card from a player who goes first > card from that who goes second
            {
              player1.addScore(1); //add points to the player who goes first, nothing more
              cout << "1 point to " << player1 << endl;
            }
          if (c1 < c2) //if the card from a player who goes second bigger
            {
              player2.addScore(1); //add points to a player who goes second
              first = false;
              cout << "1 point to " << player2 << endl;
            }
        }
      else
        {
          c1 = player2.playCard(Card{Card::Spades, Card::Joker});
          c2 = player1.playCard(c1);
          if (c2 < c1) //if the card from a player who goes first > card from that who goes second
            {
              player2.addScore(1); //add points to the player who goes first, nothing more
              cout << "1 point to " << player2 << endl;
            }
          if (c1 < c2) //if the card from a player who goes second bigger
            {
              player1.addScore(1); //add points to a player who goes second
              first = true;
              cout << "1 point to " << player1 << endl;
            }
        }

     //deal cards to both players
     if (!d1.isEmpty())
       {
	 player1.receiveCard(d1.draw());
	 player2.receiveCard(d1.draw());
       }

     player1.cardsPlayed(c1, c2);
     player2.cardsPlayed(c1, c2);

     cout << endl;
   }

   if (player1.getScore() > player2.getScore())
     {
       cout << player1 << " won! Score: " << player1.getScore()
      	    << " vs " << player2.getScore() << endl;
     }
   else if (player2.getScore() > player1.getScore())
          {
            cout << player2 << " won! Score: " << player2.getScore()
                 << " vs " << player1.getScore() << endl;
          }
   else
     {
       cout << "The scores are equal. Ties!" << endl;
     }
}


