//
//  Sem2_3.cpp
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

// "23" % 7 -- 2 // a
// 10 * k + b --> (10 * 2 + 3) % 7
// 3 * k + b

// remainderMod7("1234")
// (10 * remainderMod7("123") + 4) % 7
//..sss
// 10 * remainderMod7("") + 1


int remainderMod7(string str) {
    if(str.length() == 0) return 0;
    // b
    int lastDigit = str[str.length() - 1] - '0';
    string remainingStr = str.substr(0, str.length() - 1);
    // 3 *
    return (3 * remainderMod7(remainingStr) + lastDigit) % 7;
}

int main()
{
    cout << remainderMod7("21") << endl;
    cout << remainderMod7("23") << endl;
    return 0;
}
