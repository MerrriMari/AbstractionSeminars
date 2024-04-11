//
//  Sem2_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 08.04.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "set.h"
#include <fstream>
#include "tokenscanner.h"

bool canSumUpWithUnits(int amount, Vector<int> &units) {
    if(amount == 0) return true;
    if(amount < 0) return false;
    
    bool canSumUp = false;
    int curr;
    for(int i = 0; i < units.size(); i++) {
        curr = units.get(i);
//        canSumUp = canSumUp || canSumUpWithUnits(amount - curr, units);
        if(canSumUpWithUnits(amount - curr, units)) return true;
    }
    return canSumUp;
}


int main() {
    Vector<int> vec;
    vec.add(3);
    vec.add(5);
    vec.add(11);
    cout << canSumUpWithUnits(19, vec) << endl;
    cout << canSumUpWithUnits(23, vec) << endl;
    return 0;
}
