//
//  Amoc1_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 11.03.24.
//

#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

int remainderOnSeven(int n) {
    if(n < 10) return n % 7;
    int lastDig = n % 10;
    return (3 * remainderOnSeven(n/10) + lastDig) % 7;
}

int main() {
    cout << remainderOnSeven(234) << endl;
    return 0;
}
