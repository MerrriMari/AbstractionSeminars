//
//  BSTTwo.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 31.05.24.
//

#include "BSTTwo.hpp"
#include "console.h"
#include "iostream"

using namespace std;


BSTTwo::BSTTwo() {
    root = NULL;
}

void BSTTwo::deleteSubtree(Node *ptr) {
    if(ptr == NULL) return;
    deleteSubtree(ptr -> left);
    deleteSubtree(ptr -> right);
    delete ptr;
}

BSTTwo::~BSTTwo() {
    deleteSubtree(root);
}

// Node*& - reference of node pointer
// Node** - pointer of node pointer

BSTTwo::Node*& BSTTwo::findPlaceFor(Node*& ptr, int val) {
    if(ptr == NULL) return ptr;
    if(ptr -> val > val) {
        return findPlaceFor(ptr -> left, val);
    } else {
        return findPlaceFor(ptr -> right, val);
    }
}

void BSTTwo::add(int val) {
    if(root == NULL) {
        root = new Node(NULL, NULL, val);
        return;
    }
    Node*& holder = findPlaceFor(root, val);
    holder = new Node(NULL, NULL, val);
}

bool BSTTwo::containsBelow(Node* ptr, int val) {
    if(ptr -> val == val) return true;
    if(ptr == NULL) return false;
    if(ptr -> val > val) {
        return findPlaceFor(ptr -> left, val);
    } else {
        return findPlaceFor(ptr -> right, val);
    }
}

bool BSTTwo::contains(int val) {
    return containsBelow(root, val);
}

void BSTTwo::printBelow(Node *ptr) {
    if(ptr == NULL) return;
    printBelow(ptr -> left);
    cout << ptr -> val << " ";
    printBelow(ptr -> right);
}

void BSTTwo::print() {
    printBelow(root);
}
