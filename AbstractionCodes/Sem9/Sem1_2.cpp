//
//  Sem1_2.cpp
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

bool canSumUp(int amount, Vector<int> &units) {
    if(amount == 0) return true;
    if(amount < 0) return false;
    bool canSumup = false;
    Set<int> set;
    for(int i = 0; i < units.size(); i++) {
        int currUnit = units.get(i);
        canSumup |= canSumUp(amount - currUnit, units);
//        canSumup = canSumup || canSumUp(amount - currUnit, units);
        if(canSumUp(amount - currUnit, units)) return true;
    }
    return false;
}

int main() {
    Vector<int> vec;
    vec.add(3);
    vec.add(5);
    vec.add(10);
    cout << canSumUp(28, vec) << endl;
    cout << canSumUp(27, vec) << endl;
    return 0;
}

