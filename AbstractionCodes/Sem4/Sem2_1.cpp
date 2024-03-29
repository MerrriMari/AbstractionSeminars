//
//  Sem2_1.cpp
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

const string IN_FILE_NAME = "infile.txt";
const string OUT_FILE_NAME = "outfile.txt";

void readFile(string fileName, Stack<string> &words) {
    ifstream infile;
    infile.open(fileName);
    
    TokenScanner scan;
    scan.ignoreWhitespace();
    scan.setInput(infile);
    while (scan.hasMoreTokens()) {
        string word = scan.nextToken();
        words.push(word);
    }
    infile.close();
}

void writeFile(string fileName, Stack<string> &words) {
    ofstream outfile;
    outfile.open(fileName);
    
    string wholeInpText = "";
    while (!words.isEmpty()) {
        string word = words.pop();
        wholeInpText += word + " ";
    }
    wholeInpText = wholeInpText.substr(0, wholeInpText.length() - 1);
    outfile << wholeInpText << endl;
    outfile.close();
}

int main() {
    Stack<string> words;
    readFile(IN_FILE_NAME, words);
    writeFile(OUT_FILE_NAME, words);
    cout << endl;
    return 0;
}
