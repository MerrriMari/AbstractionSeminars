#include "ListSum.hpp"
#include "stdlib.h"
#include "simpio.h"
#include "foreach.h"
#include "console.h"
#include <iostream>
#include <string>
using namespace std;

digit* reverseList(digit *list) {
    digit* next = NULL;
    digit* prev = NULL;
    while(list != NULL) {
        next = list -> next; // 1 2 3 4
        list -> next = prev; //
        prev = list;
        list = next;
    }
    return prev;
}

void printlist(digit * list) {
    while(list != NULL) {
        cout << list -> d << " ";
        list = list -> next;
    }
    cout << endl;
}

digit* sumTwoList(digit * first, digit* second) {
    int e = 0;
    digit* head = new digit(); // dummy digit
    head -> next = NULL;
    digit* ptr = head;
    
    while (first != NULL || second != NULL || e != 0) { // 2 3 4 // 5 6 6 // 7 9 0 ( e - 1)
        int firstD = first == NULL ? 0 : first -> d;
        int secondD = second == NULL ? 0 : second -> d;
        int sum = firstD + secondD + e;
        e = sum / 10;
        
        digit* newDigit = new digit();
        newDigit->d = sum % 10;
        newDigit->next = NULL;
        
        ptr->next = newDigit;
        ptr = newDigit;
        
        if(first != NULL) first = first -> next;
        if(second != NULL) second = second -> next;
    }
    return head -> next;
}

digit * sum(digit * first, digit* second) {
    digit* reversedFirst = reverseList(first);
    printlist(reversedFirst);
    digit* reversedSecond = reverseList(second);
    return reverseList(sumTwoList(reversedFirst, reversedSecond));
}
