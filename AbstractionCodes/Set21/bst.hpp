//
//  bst.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 31.05.24.
//

#ifndef bst_hpp
#define bst_hpp

#include <stdio.h>

class bst {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(Node* l, Node* r, int val = 0) {
            left = l;
            right = r;
            value = val;
        }
    };
    Node* root;
    void deleteFromBelow(Node* root);
    Node* findPlaceFor(Node *ptr, int val);
    bool containsBelowCurr(Node *ptr, int val);
    void printBelow(Node *ptr);
public:
    bst();
    ~bst();
    void add(int val);
    bool contains(int val);
    void print();
};

#endif /* bst_hpp */
