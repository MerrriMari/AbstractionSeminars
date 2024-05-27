//
//  LString.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 27.05.24.
//

#ifndef LString_hpp
#define LString_hpp

#include <stdio.h>
#include <string>
using namespace std;

class LString {
private:
    struct Node {
        char chr;
        Node* next;
        Node(char chr, Node* next) {
            this -> chr = chr;
            this -> next = next;
        }
    };
    Node* head;
    int size;
    Node* copyy(Node* hd);
public:
    LString(const LString& s);
    LString(string s);
    ~LString();
    string toString();
    LString operator+ (const LString& s);
};

#endif /* LString_hpp */
