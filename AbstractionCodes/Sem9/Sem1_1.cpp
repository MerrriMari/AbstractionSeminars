//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 08.04.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "set.h"
#include <fstream>
#include "tokenscanner.h"

int finMin(Vector<int> &vec) {
    int mini = INT_MAX;
    for(int i = 0; i < vec.size(); i++) {
        mini = min(mini, vec.get(i));
    }
    return mini;
}

int finMinRec(Vector<int> &vec, int index = 0) {
    if(vec.size() == index) return INT_MAX;
    return min(vec.get(index), finMinRec(vec, index + 1));
}


int main() {
    Vector<int> vec;
    vec.add(3);
    vec.add(4);
    vec.add(-5);
    vec.add(-11);
    vec.add(30);
    cout << finMin(vec) << endl;
    cout << finMinRec(vec) << endl;
    return 0;
}
