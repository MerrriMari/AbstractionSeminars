//
//  Sem2_1.cpp
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

int finMin(Vector<int> &vec, int index) {
    if(index == vec.size()) return INT_MAX;
    return min(vec.get(index), finMin(vec, index + 1));
}

int main() {
    Vector<int> vec;
    vec.add(4);
    vec.add(-3);
    vec.add(5);
    vec.add(9);
    vec.add(-3);
    cout << finMin(vec, 0) << endl;
    return 0;
}
