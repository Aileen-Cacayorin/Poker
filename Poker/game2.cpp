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

#include "game2.hpp"


using namespace nsgame2;
using namespace nshand;
using namespace std;

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
//    csis << n+1 <<"\t"<< totalHands << "\t\t" << getTotalPairs() <<"\t\t" << getTotalFlushes() << "\t" << calculatePairPercentage() << "%\t" << calculateFlushPercentage() << "%" << endl;
    
    cout << n+1 <<"\t"<< totalHands << "\t\t" << getTotalPairs() <<"\t\t" << getTotalFlushes() <<"\t" << calculatePairPercentage() << "%\t" << calculateFlushPercentage() << "%" << endl;
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
