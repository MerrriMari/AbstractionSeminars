//
//  Sem2_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

const int sentinel = -1;

void reverseEnteredIntegers() {
    Stack<int> st;
    while(true) {
        int input = getInteger("Enter next int: ");
        if(input == sentinel) break;
        st.push(input);
    }
    cout << "Reversed integer: ";
    // bottom | e1, e2 ... en | top
    while(!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    cout << endl;
}

int main() {
    reverseEnteredIntegers();
    return 0;
}
