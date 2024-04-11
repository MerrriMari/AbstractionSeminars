//
//  Sem2_3.cpp
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

bool canSumUpWithUniqueUnits(int amount, Vector<int> &uniqueUnits, int index) {
    if(amount == 0) return true;
    if(uniqueUnits.size() == index) return false;
    
    int currUnit = uniqueUnits.get(index);
    bool canSumUp = false;
    // use this currUnti
    canSumUp = canSumUp || canSumUpWithUniqueUnits(amount - currUnit, uniqueUnits, index + 1);
    // use this currUnti
    canSumUp = canSumUp || canSumUpWithUniqueUnits(amount, uniqueUnits, index + 1);
    
    return canSumUp;
}

int main() {
    Vector<int> vec;
    vec.add(3);
    vec.add(5);
    vec.add(11);
    vec.add(3);
    cout << canSumUpWithUniqueUnits(19, vec, 0) << endl;
    cout << canSumUpWithUniqueUnits(23, vec, 0) << endl;
    return 0;
}
