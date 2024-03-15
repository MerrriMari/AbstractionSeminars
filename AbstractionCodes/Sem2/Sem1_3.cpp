//
//  Sem1_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 15.03.24.
//

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include <cctype>
#include <cstring>


int remainderOnSeven(int n) {
    if(n < 10) return n % 7;
    int lastDig = n % 10;
    return (3 * remainderOnSeven(n/10) + lastDig) % 7;
}


int remainderMod7(string num) {
    if(num.length() == 0) return 0;
    int lastDigit = num[num.length() - 1] - '0';
    string remainingNum = num.substr(0, num.length() - 1);
    // * 3 ; * 10
    return (remainderMod7(remainingNum) * 10 + lastDigit) % 7;
}


int main() {
    cout << remainderMod7("21") << endl;
    cout << remainderMod7("23") << endl;
    return 0;
}
