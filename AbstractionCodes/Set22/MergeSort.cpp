//
//  MergeSort.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 03.06.24.
//

#include <stdio.h>
#include "simpio.h"
#include "iostream"
#include "console.h"

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val, Node* next) {
        this -> val = val;
        this -> next = next;
    };
    Node() {
        
    }
};

int getSize(Node* list) {
    int size = 0;
    while(list != NULL) {
        size++;
        list = list -> next;
    }
    return size;
}

Node* merge(Node* list1, Node* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    Node* minNode;
    if(list1 -> val > list2 -> val) {
        minNode = list2;
        minNode -> next = merge(list1, list2 -> next);
    } else {
        minNode = list1;
        minNode -> next = merge(list1 -> next, list2);
    }
    return minNode;
}

Node* getSecondHalf(Node* list, int firstHalfSize) {
    for(int i = 0; i < firstHalfSize - 1; i++) {
        list = list -> next;
    }
    Node* secondHalf = list -> next;
    list -> next = NULL;
    return secondHalf;
}

void sortWithSize(Node*& list, int size) {
    if(size <= 1) return;
    // split this list --> list 1 list 2
    Node* secondList = getSecondHalf(list, size/2);
    // sortWithSize - lis11
    sortWithSize(list, size/2);
    // sortWithSize - list2
    sortWithSize(secondList, size - size/2);
    // merge sorted lists - list1, list2
    list = merge(list, secondList);
    // return mergelist
}

void sort(Node*& list) {
    if(list == NULL) return;
    int size = getSize(list);
    sortWithSize(list, size);
}

void displayList(Node* list) {
    while(list != NULL) {
        cout << list -> val << " ";
        list = list -> next;
    }
}

int main() {
    Node* listMyList = new Node(7, NULL); // 3 -> 4 -> 1
    // 1 -> 3 -> 4
    Node* ptr = listMyList;
    Node* node = new Node();
    ptr -> next = new Node(3, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(2, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(16, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(24, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(4, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(11, NULL);
    ptr = ptr -> next;
    ptr -> next = new Node(9, NULL);
    sort(listMyList);
    displayList(listMyList);
    cout << endl;
    return 0;
}
