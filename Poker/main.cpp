//
//  main.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include "main.hpp"
#include "game1.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>


using namespace std;

void printHeader() {
    cout << "Trial  ";
    cout << "# of Hands ";
    cout << "# of Flushes   ";
    cout << "# of Pairs     ";
    cout << "Flush %     ";
    cout << "Pair % " <<endl;
};

void runTrial(int n) {
    for (int i=0; i < n; i++) {
        Game poker(10000);
        for (int i=0; i<poker.totalHands; i++) {
            poker.playHand();
        }
        cout << "\t" << i+1 <<"\t\t"<< poker.totalHands << "\t\t" << poker.getTotalFlushes() << "\t\t\t" << poker.getTotalPairs() <<"\t\t" <<  poker.calculateFlushPercentage() << "%\t\t" <<  poker.calculatePairPercentage() << "%" << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((unsigned)time(NULL));
    
    int trials = 10;
    cout << fixed << setprecision(2);
    printHeader();
    runTrial(trials);
    
    return 0;
};
