//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

const int sentinel = -1;

void printStackElems(Stack<int> &st) {
    cout << "Reversed integers: ";
    while (!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    cout << endl;
}

void readAndReverseInts() {
    Stack<int> st;
    while (true) {
        int input = getInteger("Enter next integer: ");
        if(sentinel == input) break;
        st.push(input);
    }
    printStackElems(st);
}

int main() {
    readAndReverseInts();
    return 0;
}
