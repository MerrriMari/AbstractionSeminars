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

int main() {
    Stack<string> words;
    TokenScanner scan;
    scan.ignoreWhitespace();
    
    // read functionality
    ifstream infile;
    infile.open("input.txt");
    
    scan.setInput(infile);
    
    while(scan.hasMoreTokens()) {
        string word = scan.nextToken();
        words.push(word);
    }
    infile.close();
    
    string reveredText = "";
    while (!words.isEmpty()) {
        string word = words.pop();
        reveredText += word + " ";
    }
    reveredText = reveredText.substr(0, reveredText.length() - 1);
    
    // write functionality
    ofstream outfile;
    outfile.open("output.txt");
    outfile << reveredText << endl;
    outfile.close();
    
    return 0;
}
