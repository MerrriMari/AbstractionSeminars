//
//  Sem1_1.cpp
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

void swapTwoIndex(string &str, int index1, int index2) {
    char charFirst = str[index1];
    str[index1] = str[index2];
    str[index2] = charFirst;
}

string swapMinWithFirst(string str) {
    if(str.length() == 0) return str;
    
    int indexOfMin = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[indexOfMin] > str[i])
            indexOfMin = i;
    }
    // swap (0 indexOfMin)
    swapTwoIndex(str, 0, indexOfMin);
    return str;
}

int main() {
    cout << swapMinWithFirst("Mari") << endl;
    cout << swapMinWithFirst("mari") << endl;
    return 0;
}
