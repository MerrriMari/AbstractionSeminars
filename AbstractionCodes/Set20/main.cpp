//
//  main.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 27.05.24.
//

#include <stdio.h>
#include <iostream>
#include "LString.hpp"
#include "console.h"


using namespace std;

int main() {
    LString str("mari");
    cout << str.toString() << "ddd" << endl;
    LString str1(str);
    cout << str1.toString() << "ddd" << endl;
    cout << (str1 + str).toString() << "ddd" << endl;
    return 0;
}
