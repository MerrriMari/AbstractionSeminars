//
//  Sem1_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 18.03.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "stack.h"

int evaluateExpression(string str) {
    int currVal = 0;
    bool firstNum = true;
    Stack<int> st;
    int paranCount = 1;
    str = "( " + str + " )";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ' || str[i] == '-') continue;
        if(str[i] == '(' || str[i] == ')') {
            if(paranCount % 2 == 1) st.push(-1 * currVal);
            else st.push(currVal);
            if(str[i] == '(') {
                paranCount += 1;
                firstNum = true;
            } else {
                paranCount -= 1;
                currVal = 0;
            }
        } else {
            if(firstNum) {
                currVal = str[i] - '0';
                firstNum = false;
            }
            else currVal -= (str[i] - '0');
        }
    }
    cout << st.toString() << endl;
    int res = 0;
    while (st.size() > 0) {
        res += st.pop();
    }
    return res;
}

int main() {
    // 2 --2 --2
    // The signs were the actual problem during seminar, we need to consider on which level we are in order to
    // determine the sign of the curr value we are adding in our stack.
    // it is the fist ( then - (4 - 6 - ( -- in similar case need to add 2 in our stack ...
    // 1 3 4 1
    cout << evaluateExpression("2 - 4 - 6 - 2 - 4 - 5 ") << endl;
    cout << evaluateExpression("2 - (4 - 6 - (2 - 4) - 5)") << endl;
    return 0;
}
