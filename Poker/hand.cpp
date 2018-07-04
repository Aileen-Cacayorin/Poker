//
//  Hand.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/3/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "hand.hpp"

using namespace std;



Hand::Hand() {
    Card cards[5];
}


void Hand::dealCards(Deck gameDeck) {
    for (int i = 0; i < 5; i++) {
        cards[i] = gameDeck.getCard();
    }
}
bool Hand::hasFlush() {
    for (int i = 1; i < 5; i++) {
        if (cards[i].getSuit() != cards[0].getSuit())
            return 0;
    };
    return 1;
};

bool Hand::hasPair() {
    for (int i = 0; i < 4; i++) {
        for (int j = (i+1); j < 5; j++) {
            if (cards[i].getValue() == cards[j].getValue()) {
                return 1;
            }
        }
    };
    return 0;
};


