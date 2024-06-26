#include "Numbers.h"

void numsSameConsecDiffRec(int n, int k, Vector<int>& nums, int currNum) {
    if(n == 0) {
        nums.add(currNum);
        return;
    }
    // currNum - 1
    int minuKValue = currNum % 10 - k;
    if(minuKValue >= 0)
        numsSameConsecDiffRec(n - 1, k, nums, currNum * 10 + minuKValue);
    
    int plusKValue = currNum % 10 + k;
    if(minuKValue != plusKValue && plusKValue <= 9)
        numsSameConsecDiffRec(n - 1, k, nums, currNum * 10 + plusKValue);
}


Vector<int> numsSameConsecDiff(int n, int k) {
	Vector<int> nums;
    if(n <= 0) return nums;
    for(int i = 1; i <= 9; i++) {
        numsSameConsecDiffRec(n - 1, k, nums, i);
    }
	return nums;
}
