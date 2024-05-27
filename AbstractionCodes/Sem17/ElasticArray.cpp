//
//  ElasticArray.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 20.05.24.
//

#include "ElasticArray.hpp"
#include "math.h"
#include "error.h"

ElasticArray::ElasticArray(int size) {
    this -> size = size;
    data = new double[size];
    for(int i = 0; i < size; i++) data[i] = 0.0;
}

ElasticArray::~ElasticArray() {
    delete[] data;
}

int mini(int a, int b) {
    if(a > b) return b;
    else return a;
}

// resizable
void ElasticArray::resize(int size) {
    double* newArr = new double[size];
    
    for(int i = 0; i < mini(size, this -> size); i++) {
        newArr[i] = data[i];
    }
    
    if(size > this -> size) {
        for(int i = this -> size; i < size; i++)
            newArr[i] = 0.0;
    }
    
    delete[] data;
    data = newArr;
}

bool ElasticArray::isValidIndex(int index) {
    return index >= 0 && index < size;
}

// needed
double ElasticArray::get(int index) {
    if(!isValidIndex(index)) error("out of bound exept");
    return data[index];
}

void ElasticArray::set(int index, double value) {
    if(!isValidIndex(index)) error("out of bound exept");
    data[index] = value;
}

int main() {
    ElasticArray res(3);
    res.set(0, 2.0);
    res.set(1, 2.0);
    res.set(2, 2.0);
    return 0;
}
