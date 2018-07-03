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




bool isFlush(Card a[5]) {
    
    for (int i = 1; i < 5; i++) {
        if (a[i].getSuit() != a[0].getSuit())
            return 0;
    };
    return 1;
    
};

bool isPair(Card a[5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = (i+1); j < 5; j++) {
            if (a[i].getValue() == a[j].getValue()) {
                return 1;
            }
        }
    };
    return 0;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((unsigned)time(NULL));
    
    Deck gameDeck;
    Card hand[5];
    gameDeck.shuffle(rand() % 1000);
    
    for (int i = 0; i < 5; i++) {
        hand[i] = gameDeck.getCard();
        hand[i].printCard();
        cout << endl;
    }

    
    cout << isFlush(hand) << endl;
    cout << isPair(hand) << endl;
    cout << gameDeck.totalCards() << endl;
   
    return 0;
}



