//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 10.03.24.
//

#include "Sem1_1.hpp"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

const int STOP = -1;

struct statsS {
    int mini;
    int maxi;
    int sum;
    int count;
    statsS() {
        mini = INT_MAX;
        maxi = INT_MIN;
        sum = 0;
        count = 0;
    }
};

statsS getSecStats() {
    statsS dt = statsS();
    while(true) {
        cout << "Enter next integer (Enter -1 to stop): " << endl;
        int input = getInteger();
        if(input == STOP)
            break;
        dt.mini = min(dt.mini, input);
        dt.maxi = max(dt.maxi, input);
        dt.sum += input;
        dt.count += 1;
    }
    return dt;
}

int main() {
    statsS dt = getSecStats();
    cout << "Min of this sec is " << dt.mini << endl;
    cout << "Max of this sec is " << dt.maxi << endl;
    cout << "Avg of this sec is " << (double) dt.sum / dt.count << endl;
    return 0;
}


