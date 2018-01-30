# War
Individual_Final_Project_War_Card_Game_(Three_Card_War)_C++

Three Card War is a card game with a simple AI which counts cards and makes card choice based on probabilities. 
The program is written in C++ using OOP design. This was an individual final project for the C++ class (Fall 2016). 


Some game logic is explained below.
Counting Cards

Counting cards is a good way to determine how you might play your next card. While you have minimal information 
about your opponent's card you can determine the probability of your opponent having a particular card you can beat. 
Let's start with a simple example. In the beginning of the game you have an Ace in your hand. What is the probability 
of your opponent having a card that you can beat if your opponent has one card? To start there are 50 cards left in the 
deck and there are three other Aces left. We include the opponents card in the calculation because we do not know what 
they have and we exclude the card we have. If we did know the opponent's card we could exclude it, but then the game 
would not be any fun.

There are 51 unknown cards minus the 3 cards we know equal our card (an Ace). Divided by the number of unknown cards we 
get our answer.

\frac{\left(51\:-\:3\right)}{51}=94\%\:\left(approximately\right) ( 51 − 3 ) 51 = 94 % (approximately)

And you have an 6% chance of a push  and 0% chance of losing.

Let's say that you had a 10 in your hand instead of the Ace. There are 50 cards left in the deck and there are three 
other 10s left. There are eight cards that are less than your 10 (2 through 9) and 4 cards greater than your 10 
(Jack through Ace). What is the probability of your opponent having a card that you can beat?

\frac{\left(8\cdot4\right)}{51}=63\%\:\left(approximately\right) ( 8 ⋅ 4 ) 51 = 63 % (approximately)

There is a 6% chance of a push and 31% chance of losing \frac{\left(4\cdot4\right)}{51} ( 4 ⋅ 4 ) 51 .

Now let's expand on our calculations and include the three cards we are dealt when the game starts. Let's say you had 
a 10, 10, and a Jack. The probabilities for playing a 10 and beating your opponent are:

\frac{\left(8\cdot4\right)}{\left(52-3\right)}\:=\:65\% ( 8 ⋅ 4 ) ( 52 − 3 ) = 65 %

There are eight cards that are less than our 10 times the number of suits divided by the number of cards in the deck 
minus the played cards.

The probability of a push is:

\frac{2}{\left(52-3\right)}=4\% 2 ( 52 − 3 ) = 4 %

There are only two tens left to match our known two tens.

And the probability of losing is:

\frac{\left(\left(4\cdot4\right)-1\right)}{\left(52-3\right)}=31\% ( ( 4 ⋅ 4 ) − 1 ) ( 52 − 3 ) = 31 %

Note that we exclude the Jack from the calculations because we already know that card is not in the deck or in our 
opponents hand.

The probabilities for playing the Jack and beating your opponent are:

\frac{\left(\left(9\cdot4\right)-2\right)}{\left(52-3\right)}=69\% ( ( 9 ⋅ 4 ) − 2 ) ( 52 − 3 ) = 69 %

There are nine cards less than our Jack but we have two of the 10s so we remove them from the calculation.

The probability of a push is:

\frac{3}{\left(52-3\right)}=6\% 3 ( 52 − 3 ) = 6 %

And the probability of losing is:

\frac{\left(3\cdot4\right)}{\left(52-3\right)}=25\% ( 3 ⋅ 4 ) ( 52 − 3 ) = 25 %

It is interesting to note that the percentage of winning by playing the Jack is not much greater than playing the 10.
This is because we have knowledge of the cards already in play. So how do we use all this? By keeping track of the cards 
played we can calculate the probabilities of winning or losing when a particular cards is played. While your opponent can 
always "beat the odds" knowing that playing one card provides a 72% chance of winning compared to playing another card that 
provides a 12% chance of winning allow for easier decision making. 
