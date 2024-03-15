//
//  Amoc1_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 11.03.24.
//


#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

const int STOP = -1;

struct seqStats {
    int mini;
    int maxi;
    int sum;
    int cout;
    seqStats(int mini, int maxi) {
        this -> mini = mini;
        this -> maxi = maxi;
        sum = 0;
        cout = 0;
    }
};

seqStats getStatForSec() {
    seqStats data = seqStats(INT_MAX, INT_MIN);
    while(true) {
        cout << "Enter next intege: " << endl;
        int input = getInteger();
        if(input == STOP)
            break;
        data.mini = min(data.mini, input);
        data.maxi = max(data.maxi, input);
        data.sum += input;
        data.cout += 1;
    }
    return data;
}

int main() {
    seqStats st = getStatForSec();
    cout << "Min of seq is " << st.mini << endl;
    cout << "Maxi of seq is " << st.maxi << endl;
    cout << "Avg of seq is " << (double) st.sum / st.cout << endl;
    return 0;
}
