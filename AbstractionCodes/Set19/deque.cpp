//
//  deque.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 24.05.24.
//

#include "deque.hpp"
#include "error.h"

template <typename T>
Deque<T>::Deque() {
    head = new Node(NULL, NULL);
    tail = new Node(head, NULL);
    head -> next = tail;
}

template <typename T>
Deque<T>::~Deque() {
    while(head != NULL) {
        Node *tmp = head;
        head = head -> next;
        delete tmp;
    }
}

template <typename T>
bool Deque<T>::isEmpty() {
    return head -> next == tail;
}

template <typename T>
void Deque<T>::pushFront(T value) {
    Node *newNode = new Node(value, head, head -> next);
    head -> next -> prev = newNode;
    head -> next = newNode;
}

template <typename T>
void Deque<T>::pushBack(T value) {
    Node *newNode = new Node(value, tail -> prev, tail);
    tail -> prev -> next = newNode;
    tail -> prev = newNode;
}

template <typename T>
T Deque<T>::popFront() {
    if(isEmpty()) error("Empty deque");
    Node *removedNode = head -> next;
    head -> next = removedNode -> next;
    head -> next -> prev = head;
    T value = removedNode -> value;
    delete removedNode;
    return value;
}

template <typename T>
T Deque<T>::popBack() {
    if(isEmpty()) error("Empty deque");
    Node *removedNode = tail -> prev;
    tail -> prev = removedNode -> prev;
    tail -> prev -> next = tail;
    T value = removedNode -> value;
    delete removedNode;
    return value;
}

template class Deque<int>;
template class Deque<double>;
