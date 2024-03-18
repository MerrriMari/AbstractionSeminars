//
//  Sem2_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//


#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

int executeExpression(string str) {
    int curr = 0;
    Stack<int> st;
    bool firstNum = true;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ' || str[i] == '-')
            continue;
        if(str[i] == '(') {
            firstNum = true;
            st.push(curr);
        } else if(str[i] == ')') {
            curr = st.pop() - curr;
//            st.push(curr); // Was an error reason
        } else {
            if(firstNum) {
                curr = (str[i] - '0');
                firstNum = false;
            }
            else curr -= (str[i] - '0');
        }
    }
    
    return curr;
}


int main() {
    cout << executeExpression("2 - 4 - 4") << endl;
    cout << executeExpression("2 - (4 - 4 - 4 - (3 - 3))") << endl;
    cout << executeExpression("2 - 4 - 6 - 2 - 4 - 5 ") << endl;
    cout << executeExpression("2 - (4 - 6 - (2 - 4) - 5)") << endl;
    return 0;
}
