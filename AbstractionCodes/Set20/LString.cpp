//
//  LString.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 27.05.24.
//

#include "LString.hpp"
#include <string>

using namespace std;

LString::LString(string s) {
    // "mari"
    // m - a - r - i
    head = NULL;
    size = (int) s.length();
    for(int i = size - 1; i >= 0; i --) {
        Node *newNode = new Node(s[i], head);
        head = newNode;
    }
}

LString::Node* LString::copyy(Node* ptrS) {
    Node* ptr = new Node(ptrS -> chr, NULL);
    Node* hd = ptr;
    ptrS = ptrS -> next;
    while(ptrS != NULL) {
        ptr -> next = new Node(ptrS -> chr, NULL);
        ptr = ptr -> next;
        ptrS = ptrS -> next;
    }
    return hd;
}

LString::LString(const LString& s) {
    if(s.head == NULL) return;
    head = copyy(s.head);
    size = s.size;
}

LString::~LString() {
    while(head != NULL) {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
}
string LString::toString() {
    string s = "";
    Node *ptr = head;
    for(int i = 0; i < size; i++, ptr = ptr -> next) {
        s += ptr -> chr;
    }
    return s;
}

LString LString::operator+ (const LString& s) {
    LString res("");
    Node* hd = copyy(head);
    Node* tail = hd;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }
    tail -> next = copyy(s.head);
    res.head = hd;
    res.size = s.size + size;
    return res;
}
