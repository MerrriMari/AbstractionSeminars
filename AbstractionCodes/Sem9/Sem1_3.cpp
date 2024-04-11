//
//  Sem1_3.cpp
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


bool canSumUpWithUniques(int amount, Vector<int> &vec, int index = 0) {
    if(amount == 0) return true;
    if(vec.size() == index) return false;
        
    int currOneUnit = vec.get(index);
    bool canSumUp = false;
    // include/ use currOneUnit
    canSumUp |= canSumUpWithUniques(amount - currOneUnit, vec, index + 1);
    // not include/ not use currOneUnit
    canSumUp |= canSumUpWithUniques(amount, vec, index + 1);
    return canSumUp;
}


int main() {
    Vector<int> vec;
    vec.add(3);
    vec.add(5);
    vec.add(10);
    vec.add(5);
    cout << canSumUpWithUniques(18, vec) << endl;
    cout << canSumUpWithUniques(19, vec) << endl;
    return 0;
}


