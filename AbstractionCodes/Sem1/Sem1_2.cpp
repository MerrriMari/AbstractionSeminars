//
//  Sem1_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 10.03.24.
//


#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"


using namespace std;

bool isTwoPow(int n) {
    if(n == 1) return true;
    if(n % 2 == 1 || n <= 0) return false;
    return isTwoPow(n / 2);
}

int main() {
    int input = getInteger("Enter your integer: ");
    if(isTwoPow(input))
        cout << input << " is pow of two!" << endl;
    else
        cout << input << " is not pow of two!" << endl;
    return 0;
}
