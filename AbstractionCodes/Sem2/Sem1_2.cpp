//
//  Sem1_2.cpp
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

bool isInteger(string str) {
    // check for negative
    if(str.length() == 0) return false;
    if(str[0] == '-') str = str.substr(1);
    if(str.length() == 0) return false;
    for(int i = 0; i < str.length(); i++) {
        // not - '0' '1' '2' .. '9'
//      if(str[i] < '0' || str[i] > '9')
//          return false;
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

// 1234
int convertToInt(string str) {
    if(str.length() == 0) return 0;
    // 4
    int lastDigit = str[str.length() - 1]  - '0'; // '0' - '0' --> 0
    // "123"
    string remainingString = str.substr(0, str.length() - 1);
    // convertToInt -- 123
    return convertToInt(remainingString) * 10 + lastDigit;
}


int main() {
    cout << isInteger("1234") << endl;
    cout << isInteger("-1234") << endl;
    cout << convertToInt("1234") << endl;
    cout << convertToInt("mari") << endl;
    return 0;
}
