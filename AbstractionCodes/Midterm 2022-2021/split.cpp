
#include "split.h"
#include <string>
#include <iostream>


using namespace std;

long stringToLong(string s) {
    char* remaining;
    long answer;

    answer = strtol(s.c_str(), &remaining, 10);
    return answer;
}

bool splitStringRec(string s, int stIndex, long searchNum) {
    if(stIndex == s.length()) return true;
    
    // try all length stIndex...s.length
    for(int endIndex = stIndex + 1; endIndex < s.length(); endIndex++) {
        long currNum = stringToLong(s.subtr(stIndex, endIndex - stIndex));
        if(searchNum == -1 || currNum == searchNum) {
            if(searchNum == -1) searchNum = currNum;
            if(splitStringRec(s, endIndex, searchNum - 1)) return true;
        } else return false;
    }
    return true;
}


bool splitString(string s) {
    // long num = stringToLong(s);
    // start - 0
    return splitStringRec(s, 0, -1);
}
