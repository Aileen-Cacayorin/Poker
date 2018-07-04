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
#include <fstream>

using namespace std;

extern ofstream csis;

Game::Game() {
    gameDeck = Deck();
    Card hand[5];
    totalHands = 1;
    totalFlushes = 0;
    totalPairs = 0;
};

Game::Game(int hands) {
    gameDeck = Deck();
    Card hand[5];
    totalHands = hands;
    totalFlushes = 0;
    totalPairs = 0;
};

void Game::dealCards() {
    gameDeck.shuffle(100);
    for (int i = 0; i < 5; i++) {
        hand[i] = gameDeck.getCard();
    }
};

void Game::playHand() {
    dealCards();
    if (hasFlush())
        totalFlushes +=1;
    if (hasPair())
        totalPairs += 1;
    putCardsBack();
};

void Game::putCardsBack() {
    for (int i = 0; i < 5; i++) {
        gameDeck.addCard(hand[i]);
    };
};

void Game::printGameResults(int n) {
    csis << n+1 <<"\t"<< totalHands << "\t\t" << getTotalPairs() <<"\t\t" << getTotalFlushes() << "\t" << calculatePairPercentage() << "%\t" << calculateFlushPercentage() << "%" << endl;
    
    cout << n+1 <<"\t"<< totalHands << "\t\t" << getTotalPairs() <<"\t\t" << getTotalFlushes() <<"\t" << calculatePairPercentage() << "%\t" << calculateFlushPercentage() << "%" << endl;
};

int Game::getTotalFlushes() {
    return totalFlushes;
    
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

double Game::calculateFlushPercentage() {
    return (static_cast <double>(totalFlushes)/ totalHands)*100;
};

double Game::calculatePairPercentage() {
    return (static_cast <double>(totalPairs)/ totalHands)*100;
};

int Game::getTotalPairs() {
    return totalPairs;
};




