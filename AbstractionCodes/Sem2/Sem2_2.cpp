//
//  Sem2_2.cpp
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

// "12%34" - '1'
// ascii --> '0' '1' '2' ... '9'
bool isInteger(string str) {
    if(str.length() == 0) return false;
    if(str[0] == '-') str = str.substr(1);
    if(str.length() == 0) return false;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

// "1234"
//int convStringToInt(string str) {
//    int res = 0;
//    for (int i = 0; i < str.length(); i++) {
//        int lastDigit = str[str.length() - 1] - '0'; // '1' - '0'
//        res *= 10;
//        res += lastDigit; // 1 // 12 ...
//    }
//    return res;
//}

// conv("1234") --> 1234
// ==
// conv("123") * 10 + 4 --> 1234
// conv("12") * 10 + 3 --> 123
// conv("1") * 10 + 2 --> 12
// conv("") * 10 + 1 --> 1
// conv("") --> base case --> 0

int convStringToInt(string str) {
    if(str.length() == 0) return 0;
    int lastDigit = str[str.length() - 1] - '0';
    // substr(startIndex, length)
    string remainingStr = str.substr(0, str.length() - 1);
    return convStringToInt(remainingStr) * 10 + lastDigit;
}

int main() {
    cout << isInteger("1234") << endl;
    cout << isInteger("-1234") << endl;
    cout << isInteger("-") << endl;
    cout << isInteger("123%33") << endl;
    cout << convStringToInt("12333") << endl;
    return 0;
}
