//
//  main.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//


#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "game1.h"

using namespace std;

Game::Game() {
    gameDeck = Deck();
    Card hand[5];
    gameDeck.shuffle(100);
};

void Game::drawHand() {
    for (int i = 0; i < 5; i++) {
        hand[i] = gameDeck.getCard();
        hand[i].printCard();
        cout << endl;
    }
    
};


bool Game::hasFlush() {
    
    for (int i = 1; i < 5; i++) {
        if (hand[i].getSuit() != hand[0].getSuit())
            return 0;
    };
    return 1;
    
};

bool Game::hasPair() {
    for (int i = 0; i < 4; i++) {
        for (int j = (i+1); j < 5; j++) {
            if (hand[i].getValue() == hand[j].getValue()) {
                return 1;
            }
        }
    };
    return 0;
    
};








