//
//  bst.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 31.05.24.
//

#include "bst.hpp"
#include "console.h"
#include "iostream"

using namespace std;

bst::bst() {
    root = NULL;
}

void bst::deleteFromBelow(Node* root) {
    if(root == NULL) return;
    deleteFromBelow(root -> left);
    deleteFromBelow(root -> right);
    delete root;
}

bst::~bst() {
    deleteFromBelow(root);
}

bst::Node* bst::findPlaceFor(Node* ptr, int val) {
    if(ptr -> value > val) {
        if(ptr -> left == NULL) return ptr;
        return findPlaceFor(ptr -> left, val);
    } else {
        if(ptr -> right == NULL) return ptr;
        return findPlaceFor(ptr -> right, val);
    }
    return NULL;
}

void bst::add(int val) {
    Node* node = new Node(NULL, NULL, val);
    if(root == NULL) {
        root = node;
        return;
    }
    Node* currNodeParent = findPlaceFor(root, val);
    if(currNodeParent -> value > val) {
        currNodeParent -> left = node;
    } else {
        currNodeParent -> right = node;
    }
}

bool bst::containsBelowCurr(Node* ptr, int val) {
    if(ptr -> value == val) return true;
    if(ptr == NULL) return false;
    if(ptr -> value > val) {
        return findPlaceFor(ptr -> left, val);
    } else {
        return findPlaceFor(ptr -> right, val);
    }
    return false;
}

bool bst::contains(int val) {
    return containsBelowCurr(root, val);
}

void bst::printBelow(Node* ptr) {
    if(ptr == NULL) return;
//    cout << ptr -> value << " ";
    printBelow(ptr -> left);
    cout << ptr -> value << " ";
    printBelow(ptr -> right);
//    cout << ptr -> value << " ";
}

void bst::print() {
    printBelow(root);
}
