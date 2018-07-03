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



using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((unsigned)time(NULL));
    int totalFlushes = 0;
    int totalPairs = 0;
    Game poker;
    for (int i=0; i<1000; i++) {
       
        poker.dealCards();
        if (poker.hasFlush())
            totalFlushes +=1;
        if (poker.hasPair())
            totalPairs += 1;
        poker.putCardsBack();
    
    }
    cout << totalFlushes << endl;
    cout << totalPairs << endl;
    return 0;
};
