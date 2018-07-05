//
//  main.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include "main.h"
#include "game1.h"
#include "game2.h"
#include "hand.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

ofstream csis;

void printTableHeader() {                   //prints header for results table
    csis << "Trial";
    cout << "Trial";
    csis << setw(15) << "# of Hands";
    cout << setw(15) << "# of Hands";
    csis << setw(15) << "# of Pairs";
    cout << setw(15) << "# of Pairs";
    csis << setw(15) << "# of Flushes";
    cout << setw(15) << "# of Flushes";
    csis << setw(12) << "Pair %";
    cout << setw(12) << "Pair %";
    csis << setw(15) << "Flush %" << endl;
    cout << setw(15) << "Flush %" << endl;
};

void runTrial(int n) {                  // runs n trials for class Game
    printTableHeader();
    for (int i=0; i < n; i++) {
        Game poker(10000);
        for (int i=0; i<poker.totalHands; i++) {
            poker.playHand();
        }
     poker.printGameResults(i);
    }
}

void runGame2Trial(int n) {         // runs n trials for class Game2 (using class Hand)
    using namespace nsgame2;        // specify class Game2 namespace
    printTableHeader();
    for (int i=0; i <n; i++) {
        Game2 poker2(10000);
        for (int i =0; i < poker2.totalHands; i++ ) {
            poker2.playHand();
        }
        poker2.printGameResults(i);
    }
};

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    
    int numberOfTrials = 10;

    csis.open("csis1.txt");
    cout << fixed << setprecision(2);
    runTrial(numberOfTrials);
    csis.close();
    
    csis.open("csis2.txt");
    cout << fixed << setprecision(2);
    runGame2Trial(numberOfTrials);
    csis.close();
    
    return 0;
};
