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

void readFile(string fileName, Vector<string> &words) {
    ifstream infile;
    infile.open(fileName);
    
    TokenScanner scan;
    scan.ignoreWhitespace();
    scan.setInput(infile);
    while (scan.hasMoreTokens()) {
        string word = scan.nextToken();
        words.add(word);
    }
    infile.close();
}

string getConcatStrings(Vector<string> &words) {
    string wholeInpText = "";
    for(int i = 0; i < words.size(); i++) {
        string word = words.get(i);
        wholeInpText += word + " ";
    }
    wholeInpText = wholeInpText.substr(0, wholeInpText.length() - 1);
    return wholeInpText;
}

void writeFile(string fileName, Vector<string> &words) {
    ofstream outfile;
    outfile.open(fileName);
    Vector<string> oddWords, evenWords;
//    for(int i = 0; i < words; i++) {
//        if(i % 2 == 0) evenWords.add(words.get(i));
//        else oddWords.add(words.get(i));
//    }
    for(int i = 0; i < words; i+=2) evenWords.add(words.get(i));
    for(int i = 1; i < words; i+=2) oddWords.add(words.get(i));
    outfile << getConcatStrings(oddWords) + " " + getConcatStrings(evenWords) << endl;
    outfile.close();
}

int main() {
    Vector<string> words;
    readFile(IN_FILE_NAME, words);
    writeFile(OUT_FILE_NAME, words);
    cout << endl;
    return 0;
}
