//
//  Sem2_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 29.03.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "random.h"
#include "set.h"
#include <fstream>
#include "simpio.h"

void generateString(Set<string> &set) {
    Set<string> thisLevSet;
    foreach(string elem in set) {
        for(int i = 1; i < elem.length(); i++) {
            string elemCopy = elem;
            elemCopy[i - 1] = elem[i];
            elemCopy[i] = elem[i - 1];
            thisLevSet += elemCopy;
        }
    }
    set += thisLevSet;
}

void generateTillNLevelString(Set<string> &set, int depth) {
    for(int i = 0; i < depth; i++)
        generateString(set);
}

int main() {
    string st1 = getLine("Enter first string: ");
    string st2 = getLine("Enter second string: ");
    
    Set<string> set1, set2;
    set1 += st1;
    set2.insert(st2);
    
    generateTillNLevelString(set1, 2);
    generateTillNLevelString(set2, 2);
    
    Set<string> common = set1 * set2;
    if(!common.isEmpty()) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
