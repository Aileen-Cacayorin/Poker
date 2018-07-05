//
//  Hand.hpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/3/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef hand_h
#define hand_h

#include "card.h"
#include "deck.h"

#include <stdio.h>

namespace nshand {

    class Hand {
        private:
            Card cards[5];
        public:
            Hand();                         // initializes a hand
            void dealCards(Deck *deck);     // deals cards from a deck
            void putCardsBack(Deck *deck);  // returns cards in hand to deck
            bool hasFlush();                // checks if a hand has a flush
            bool hasPair();                 // checks if a hand has a pair
    };

};

#endif /* game_h */
