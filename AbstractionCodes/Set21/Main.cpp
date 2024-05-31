//
//  Main.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 31.05.24.
//

#include "bst.hpp"
#include "console.h"
#include "iostream"

using namespace std;

int main() {
    bst tree;
    tree.add(11);
    tree.add(8);
    tree.add(5);
    tree.add(9);
    tree.add(12);
    tree.add(10);
    tree.add(0);
    tree.print();
    cout << endl;
    return 0;
}
