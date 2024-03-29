//
//  Sem1_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 29.03.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "random.h"
#include "grid.h"
#include <fstream>
#include "tokenscanner.h"
#include "set.h"
#include "simpio.h"

string swapConsChars(int ind, string str) {
    char temp = str[ind];
    str[ind] = str[ind - 1];
    str[ind - 1] = temp;
    return str;
}

void generateAllSwapOp(Set<string> &set1) {
    Set<string> thisLevString;
    foreach(string elem in set1) {
        for(int i = 1; i < elem.length(); i++)
            thisLevString += swapConsChars(i, elem);
    }
    set1 += thisLevString;
}

void generateAllSwapOpN(Set<string> &set1, int opNum) {
    for(int i = 0; i < opNum; i++)
        generateAllSwapOp(set1);
}

bool dzalitSheqmniliMetodi(string str1, string str2) {
    Set<string> set1, set2;
    set1 += str1;
    set2.insert(str2);
    generateAllSwapOpN(set1,  2);
    generateAllSwapOpN(set2, 2);
    Set<string> set = set1 * set2;
    return !set.isEmpty();
}

int main() {
    string str1 = getLine("Enter first string: ");
    string str2 = getLine("Enter second string: ");
    if(dzalitSheqmniliMetodi(str1, str2)) cout << "Is achievable" << endl;
    else cout << "Is not achievable" << endl;
    return 0;
}
