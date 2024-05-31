//
//  BSTTwo.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 31.05.24.
//

#ifndef BSTTwo_hpp
#define BSTTwo_hpp

#include <stdio.h>

class BSTTwo {
private:
    struct Node {
        Node* left;
        int val;
        Node* right;
        Node(Node* l, Node* r, int v) {
            left = l;
            right = r;
            val = v;
        }
    };
    Node* root;
    void deleteSubtree(Node *ptr);
    Node*& findPlaceFor(Node*& ptr, int val);
    bool containsBelow(Node* ptr, int val);
    void printBelow(Node *ptr);
public:
    BSTTwo();
    ~BSTTwo();
    void add(int val);
    bool contains(int val);
    void print();
};

#endif /* BSTTwo_hpp */
