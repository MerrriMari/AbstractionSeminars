//
//  sem4_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 22.03.24.
//


#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"
#include <fstream>
#include "tokenscanner.h"

string getSequence(Vector<string> &words, int startIndex) {
    string wordSeq = "";
    for(int i = startIndex; i < words.size(); i += 2) {
        wordSeq += words.get(i) + " ";
    }
    return wordSeq.substr(0, wordSeq.length() - 1);
}

string getOddAndEvenIndSequences(words, 0)(Vector<string> &words) {
    // odd even
    return getSequence(words, 1) + " " + getSequence(words, 0) ;
}

int main() {
    
    Vector<string> words;
    TokenScanner scan;
    scan.ignoreWhitespace();
    
    // read functionality
    ifstream infile;
    infile.open("input.txt");
    
    scan.setInput(infile);
    
    while(scan.hasMoreTokens()) {
        string word = scan.nextToken();
        words.add(word);
    }
    infile.close();
    
    string str = getOddAndEvenIndSequences(words);
    
    ofstream outfile;
    outfile.setInput("output.txt");
    outfile << str << endl;
    outfile.close();
    
    return 0;
}
