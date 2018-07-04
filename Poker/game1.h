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
        Game();                     // constructor to initialize game
        Game(int hands);            // iniatializes with total hands to draw in a game
        void dealCards();           // draws hand of five cards
        bool hasFlush();            // checks if a hand has a flush
        bool hasPair();             // checks if a hand has a pair
        void putCardsBack();        // returns all cards in a hand to deck
        void playHand();            // shuffles deck, deals a hand, puts cards back in deck
        void printGameResults(int n);    // print game results
        int getTotalFlushes();      // returns total number of flushes in a game
        int getTotalPairs();        // returns total number of pairs in a game
        double calculateFlushPercentage(); //returns percentage of flushes in a game
        double calculatePairPercentage();       // returns percentage of pairs in a game
    
    
    
};



#endif /* game_h */
