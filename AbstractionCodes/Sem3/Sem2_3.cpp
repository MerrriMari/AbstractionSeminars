//
//  Sem2_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

// 0 (ind - 0) 1 (1) 1 (2) 2 (3)...
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(3) << endl;
    cout << fib(5) << endl;
    return 0;
}
