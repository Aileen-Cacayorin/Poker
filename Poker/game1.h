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
    public:
        Game();                     // constructor to initialize game
        void drawHand();            // draws hand of five cards
        bool hasFlush();             //
        bool hasPair();
        void startGame();
    
    
};



#endif /* game_h */
