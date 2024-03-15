//
//  Sem2_1.cpp
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


//string swapTwoInds(string str, int index1, int index2) {
//    char temp = str[index1];
//    str[index1] = str[index2];
//    str[index2] = temp;
//    return str;
//}

void swapTwoInds(string &str, int index1, int index2) {
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
}

string swapMinWithFirst(string str) {
    if(str.length() == 0) return str;
    // "mari"
    int minCharInd = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] < str[minCharInd])
            minCharInd = i;
    }
    // swap 0 , minCharInd
//    str = swapTwoInds(str, 0, minCharInd);
     swapTwoInds(str, 0, minCharInd);
    return str;
}

int main() {
    cout << swapMinWithFirst("mari") << endl;
    return 0;
}
