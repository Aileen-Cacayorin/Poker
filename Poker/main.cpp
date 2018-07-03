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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((unsigned)time(NULL));
    
    int trials = 10;
    cout << "Trial #\t # of Hands\t Flushes\t Pairs\t Flush %\t Pair %\t" <<endl;
    for (int i=0; i < trials; i++) {
    
        Game poker(10000);
        for (int i=0; i<poker.totalHands; i++) {
            poker.playHand();
        }
        cout << fixed << setprecision(2);
        cout << "\t" << i+1 <<"\t\t"<< poker.totalHands << "\t\t" << poker.getTotalFlushes() << "\t\t" << poker.getTotalPairs() <<"\t\t" <<  poker.calculateFlushPercentage() << "%\t\t" <<  poker.calculatePairPercentage() << "%" << endl;
        
    }
    
   
   
    
    return 0;
};
