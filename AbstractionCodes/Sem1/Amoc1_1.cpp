//
//  Amoc1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 11.03.24.
//

#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

const int STOP = -1;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    while(true) {
        int a = getInteger("Enter a: ");
        if(a == STOP)
            break;
        int b = getInteger("Enter b: ");
        cout << gcd(a, b) << endl;
    }
    return 0;
}
