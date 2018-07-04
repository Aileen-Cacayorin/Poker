//
//  main.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include "main.hpp"
#include "game1.h"
#include "game2.hpp"
#include "hand.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

ofstream csis;

void printTableHeader() {
    csis << "Trial  ";
    cout << "Trial  ";
    csis << "# of Hands ";
    cout << "# of Hands ";
    csis << "# of Pairs ";
    cout << "# of Pairs ";
    csis << "# of Flushes ";
    cout << "# of Flushes ";
    csis << "Pair %     ";
    cout << "Pair %     ";
    csis << "Flush %" << endl;
    cout << "Flush %" << endl;
};

void runTrial(int n) {
    for (int i=0; i < n; i++) {
        Game poker(10000);
        for (int i=0; i<poker.totalHands; i++) {
            poker.playHand();
        }
     poker.printGameResults(i);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((unsigned)time(NULL));
    
//    int numberOfTrials = 10;
//
//    csis.open("csis1.txt");
//    cout << fixed << setprecision(2);
//    printTableHeader();
//    runTrial(numberOfTrials);
//    csis.close();
    
    //using game2 and hand class
    
    using namespace nsgame2;
    printTableHeader();
    int n=1;
    for (int i=0; i <n; i++) {
        Game2 poker2(10000);
        for (int i =0; i < poker2.totalHands; i++ ) {
          poker2.playHand();
        }
        poker2.printGameResults(i);
    };
    return 0;
};
