//
//  sem4_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 22.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"


// 0 1 1 2 3 (ind 5)
//int fib(int n) {
//    if(n <= 1) return n;
//    return fib(n - 1) + fib(n - 2);
//}


struct str {
    int first;
    int second;
    str(int a, int b) {
        first = a;
        second = b;
    }
};

str fibStr(int n) {
    if(n <= 1) return str(0, 1);
    str st = fibStr(n - 1);
    int curr = st.first + st.second;
    st.first = st.second; // prev fib
    st.second = curr;  // curr fib
    return st;
}

int main() {
    cout << fibStr(5).second << endl;
    return 0;
}
