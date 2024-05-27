//
//  deque.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 24.05.24.
//

#ifndef deque_hpp
#define deque_hpp

#include <stdio.h>

template <typename T>

class Deque {
private:
    struct Node {
        Node *prev;
        T value;
        Node *next;
        Node(T value, Node *prev, Node *next) {
            this -> value = value;
            this -> prev = prev;
            this -> next = next;
        }
        Node(Node *prev, Node *next) {
            this -> prev = prev;
            this -> next = next;
        }
    };
    Node *head;
    Node *tail;
public:
    Deque();
    ~Deque();
    bool isEmpty();
    void pushFront(T value);
    void pushBack(T value);
    T popFront();
    T popBack();
};

#endif /* deque_hpp */
