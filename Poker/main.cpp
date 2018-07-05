//
//  main.cpp
//  Poker
//
//  Created by Aileen Cacayorin on 7/2/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

//  Name: Aileen Cacayorin
//  Palomar ID: 011519388
//  Title: Poker Lab
//  Compiler: XCode 9.2

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

void printMyInfo() {                             //print my student ID and compiler details
    csis << "Name: Aileen Cacayorin" << endl;
    csis << "Palomar ID: 011519388" << endl;
    csis << "Title: Poker Lab" << endl;
    csis << "Compiler: XCode 9.2" << endl;
}

void printTableHeader() {                       //prints header for results table
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

double getAverage(double sum) {     // get averages for all 10 trials
    return sum/10;
};

void printTotalPercentages(double pairSum, double flushSum ) {      //  outputs total percentage of pairs or sum for all trials
    csis << fixed << setprecision(2);
    cout << fixed << setprecision(2);
    csis << "Overall pair %: " << getAverage(pairSum) << endl;
    cout << "Overall pair %: " << getAverage(pairSum) << endl;
    csis << "Overal flush %: " << getAverage(flushSum) << endl;
    cout << "Overal flush %: " << getAverage(flushSum) << endl;
    
}

void runTrial(int n) {          // runs n trials for class Game
    printMyInfo();
    printTableHeader();
    double pairPercentageSum = 0.0;
    double flushPercentageSum = 0.0;
    
    for (int i=0; i < n; i++) {
        Game poker(10000);
        for (int i=0; i<poker.totalHands; i++) {
            poker.playHand();
        }
        pairPercentageSum += poker.calculatePairPercentage();
        flushPercentageSum += poker.calculateFlushPercentage();
        poker.printGameResults(i);
    }
    printTotalPercentages(pairPercentageSum, flushPercentageSum);
}

void runGame2Trial(int n) {         // runs n trials for class Game2 (using class Hand)
    using namespace nsgame2;
    {
        printMyInfo();
        printTableHeader();
        double pairPercentageSum = 0.0;
        double flushPercentageSum = 0.0;
        
        for (int i=0; i <n; i++) {
            Game2 poker2(10000);
            for (int i =0; i < poker2.totalHands; i++ ) {
                poker2.playHand();
            }
            pairPercentageSum += poker2.calculatePairPercentage();
            flushPercentageSum += poker2.calculateFlushPercentage();
            poker2.printGameResults(i);
        }
        printTotalPercentages(pairPercentageSum, flushPercentageSum);
    };
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
