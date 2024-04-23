
#include "boxes.hpp"
#include "set.h"
#include <string>
#include <iostream>

using namespace std;


// seminari 1

//bool canDivideBoxesRec(int n, Vector<int>& boxes, int target, int currWeight, Set<int> &visitIndices) {
//    if(n == 0) return true;
//    
//    if(currWeight == target) {
//        return canDivideBoxesRec(n - 1, boxes, target, 0, visitIndices);
//    }
//    if(currWeight > target) return false;
//    
//    for(int i = 0; i < boxes.size(); i++) {
//        if(!visitIndices.contains(i)) {
//            visitIndices.add(i);
//            if(canDivideBoxesRec(n, boxes, target, currWeight + boxes.get(i), visitIndices))
//                return true;
//            visitIndices.remove(i);
//        }
//    }
//    
//    return false;
//    
//    for(int box : boxes) {
//        if(box > target) return false;
//    }
//    return true;
//}
//
//bool canDivideBoxes(int n, Vector<int>& boxes) {
//    int sum = 0;
//    for(int box : boxes) {
//        sum += box;
//    }
//    if(sum % n != 0) return false;
//    int target = sum / n; // 4
//    Set<int> visitIndices;
////    canDivideBoxesRec(n, boxes, target, 0, visitIndices);
//    return canDivideBoxesRec(n, boxes, target, 0, visitIndices);
//}

// seminari 2

bool canDivideBoxesRes(int n, Vector<int>& boxes, int target, int currWeight) {
    if(n == 0) return true;
    
    if(currWeight == target) {
        return canDivideBoxesRes(n - 1, boxes , target, 0);
    }
    
    for(int i = 0; i < boxes.size(); i++) {
        int weight = boxes.get(i);
        if(weight != 0) {
            boxes.set(i, 0);
            if(canDivideBoxesRes(n, boxes, target, currWeight + weight))
                return true;
            boxes.set(i, weight);
        }
    }
    return false;
}


bool canDivideBoxes(int n, Vector<int>& boxes) {
    int sum = 0;
    for(int box : boxes) {
        sum += box;
    }
    if(sum % n != 0) return false;
    return canDivideBoxesRes(n, boxes, sum/n, 0);
}



















