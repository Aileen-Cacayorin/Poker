//
//  game2.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/3/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "game2.h"

using namespace nsgame2;
using namespace nshand;
using namespace std;

extern ofstream csis;

Game2::Game2() {
    gameDeck = Deck();
    totalHands = 1;
    totalFlushes = 0;
    totalPairs = 0;
};

Game2::Game2(int hands) {
    gameDeck = Deck();
    totalHands = hands;
    totalFlushes = 0;
    totalPairs = 0;
};

void Game2::playHand() {
    gameDeck.shuffle(100);
    Hand gameHand;
    Deck *dptr = &gameDeck;
    gameHand.dealCards(dptr);
    if (gameHand.hasFlush())
        totalFlushes +=1;
    if (gameHand.hasPair())
        totalPairs += 1;
    gameHand.putCardsBack(dptr);
};

void Game2::printGameResults(int n) {
    csis << fixed << setprecision(2);
    csis << n+1 << setw(15) << totalHands << setw(15) << getTotalPairs() << setw(15) << getTotalFlushes() << setw(15) << calculatePairPercentage() << setw(15)<< calculateFlushPercentage() << endl;
    
    cout << n+1 <<setw(15) << totalHands << setw(15) << getTotalPairs() <<setw(15) << getTotalFlushes() << setw(15) << calculatePairPercentage() <<setw(15) << calculateFlushPercentage() << endl;
};

int Game2::getTotalFlushes() {
    return totalFlushes;
};

int Game2::getTotalPairs() {
    return totalPairs;
};

double Game2::calculateFlushPercentage() {
    return (static_cast <double>(totalFlushes)/ totalHands)*100;
};

double Game2::calculatePairPercentage() {
    return (static_cast <double>(totalPairs)/ totalHands)*100;
};
