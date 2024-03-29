//
//  Sem2_4.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 22.03.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"
#include <fstream>
#include "tokenscanner.h"

const int ALPHABET_SIZE = 26;
const int COUNT_DEF = 0;

int main() {
    Vector<int> charFreq(ALPHABET_SIZE, COUNT_DEF);
    ifstream infile;
    infile.open("input.txt");
    char chr;
    while(infile >> chr) {
        chr = tolower(chr);
        if(chr >= 'a' && chr <= 'z') {
            charFreq[chr - 'a'] ++;
        }
    }
    infile.close();
    
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        cout << (char)('a' + i) << "'s freq is " << charFreq[i] << endl;
    }
    return 0;
}

