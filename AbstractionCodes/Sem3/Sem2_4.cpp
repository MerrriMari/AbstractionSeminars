//
//  Sem3_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

// 0 (ind - 0) 1 (1) 1 (2) 2 (3)...
struct pairS {
    int first;
    int second;
    pairS(int first, int second) {
        this -> first = first;
        this -> second = second;
    }
};
// 1 - (0, 1) 2 - (1, 1); 3 - (1, 2)
pairS fibPr(int n) {
    if(n == 1) return pairS(0, 1);
    pairS prev = fibPr(n-1);
    int temp = prev.first;
    prev.first = prev.second;
    prev.second = prev.second + temp;
    return prev;
}

int fib(int n, int &x, int &y) {
    if(n <= 1) return n;
    x = fib(n-1, x, y) + y; // fib n-1 fib n-2
    y = x - y; //
//    cout << y << endl;
    return x; // f n
}

//int fib(int n) {
//    if(n == 0) return 0;
//    pairS prev = fibPr(n);
//    return prev.second;
//}

int main() {
    // 0 1 1 2 3 5
    int x = 0, y = 0;
    cout << fib(3, x, y) << endl;
    x = 0;
    y = 0;
    cout << fib(5, x, y) << endl;
    return 0;
}
