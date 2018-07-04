//
//  game2.hpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/3/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef game2_hpp
#define game2_hpp

#include <stdio.h>
#include "hand.hpp"

#include "card.h"
#include "deck.h"
#include "hand.hpp"

namespace nsgame2 {
    class Game2 {
        private:
            Deck gameDeck;
            int  totalFlushes;
            int  totalPairs;
        
        public:
            int totalHands;
            Game2();                     // constructor to initialize game
            Game2(int hands);            // iniatializes with total hands to draw in a game
            void putCardsBack();        // returns all cards in a hand to deck
            void playHand();            // shuffles deck, deals a hand, puts cards back in deck
            void printGameResults(int n);    // print game results
            int getTotalFlushes();      // returns total number of flushes in a game
            int getTotalPairs();        // returns total number of pairs in a game
            double calculateFlushPercentage(); //returns percentage of flushes in a game
            double calculatePairPercentage();       // returns percentage of pairs in a game
        
    };
}

#endif /* game2_hpp */
