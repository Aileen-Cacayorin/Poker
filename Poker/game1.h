//
//  game.h
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef game_h
#define game_h

#include "card.h"
#include "deck.h"

class Game {
    private:
        Deck gameDeck;
        Card hand[5];
        int  totalFlushes;
        int  totalPairs;
    
    public:
        int totalHands;
        Game();                                 // constructor to initialize a game
        Game(int hands);                        // iniatializes a game with total hands to draw
        void dealCards();                       // deals hand of five cards
        void putCardsBack();                    // returns all cards in a hand to deck
        void playHand();                        // shuffles deck, deals a hand, puts cards back in deck
        void printGameResults(int n);           // prints game results
        bool hasFlush();                        // checks if a hand has a flush
        bool hasPair();                         // checks if a hand has a pair
        int getTotalFlushes();                  // returns total number of flushes in a game
        int getTotalPairs();                    // returns total number of pairs in a game
        double calculateFlushPercentage();      // returns percentage of flushes in a game
        double calculatePairPercentage();       // returns percentage of pairs in a game
};

#endif /* game_h */
