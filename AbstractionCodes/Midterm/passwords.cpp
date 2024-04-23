
#include "passwords.hpp"
#include <iostream>

// seminari 1

//void getAllPossiblePasswordsRec(int n, string digits, Set<string> &passwords, string currPass) {
//    if(n == -1) {
//        passwords.add(currPass);
//        return;
//    }
//    passwords.add(currPass);
//    
//    for(char digit : digits) {
//        getAllPossiblePasswordsRec(n - 1, digits, passwords,currPass + digit);
//    }
//}

//Set<string> getAllPossiblePasswords(int n, string digits) {
//    Set<string> passwords;
//    getAllPossiblePasswordsRec(n, digits, passwords, "");
//    return passwords;
//}

// seminari 2

void getAllPossiblePasswordsRec(int index, int n, string digits, Set<string> &passwords, string currPass) {
    if(index == n + 1) return;
    passwords.add(currPass);
    for(char digit : digits) {
        getAllPossiblePasswordsRec(index + 1, n, digits, passwords, currPass + digit);
    }
}

Set<string> getAllPossiblePasswords(int n, string digits) {
    Set<string> passwords;
    getAllPossiblePasswordsRec(0, n, digits, passwords, "");
    return passwords;
}
