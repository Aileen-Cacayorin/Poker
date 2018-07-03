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
    Game poker;
    for (int i=0; i<100; i++) {
       
        poker.dealCards();
        cout << poker.hasFlush() << endl;
        cout << poker.hasPair() << endl;
        poker.putCardsBack();
        cout << endl;
    }
    return 0;
};
