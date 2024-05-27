//
//  ArtVector.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 24.05.24.
//

#include "ArtVector.hpp"

ArtVector::ArtVector() {
    realSize = 0;
}

int ArtVector::size() {
    return realSize;
}

double ArtVector::get(int index) {
    return arr.get(index);
}
void ArtVector::set(int index, double value) {
    arr.set(index, value);
}

// vector methods
void ArtVector::add(double value) {
    if(arr.size() <= realSize) {
        arr.resize(arr.size() * 2);
    }
    realSize++;
    arr.set(realSize - 1, value);
}

void ArtVector::remove(int index) {
    for(int i = index + 1; i < realSize; i++) {
        int curr = arr.get(i);
        arr.set(i - 1, curr);
    }
    realSize --;
    
    if(2 * realSize <= arr.size()) {
        arr.resize(arr.size() / 2);
    }
}
