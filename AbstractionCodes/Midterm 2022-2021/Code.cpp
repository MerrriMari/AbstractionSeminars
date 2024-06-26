#include "Code.h"

void generateCodesRec(int n, string symbols, Vector<string> &codes, string currPass) {
    if(n == 0) {
        codes.add(currPass);
//        cout << currPass << endl;
        return;
    }
    // n - 2 symbols - "ab" ""
    for(char ch : symbols) {
        generateCodesRec(n - 1, symbols, codes, currPass + ch);
    }
}

Vector<string> generateCodes(int n, string symbols) {
    cout << n << endl;
	Vector<string> codes;
    generateCodesRec(n, symbols, codes, "");
	return codes;
}
