//
//  matrix.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 20.05.24.
//

#include "matrix.hpp"
#include "error.h"

// constructors
Matrix::Matrix(int w, int h) {
    this -> w = w;
    this -> h = h;
    data = new double[w * h];
    for(int i = 0; i < w * h; i++)
        data[i] = 0.0;
}
Matrix::Matrix(const Matrix& matrix) {
    this -> w = matrix.w;
    this -> h = matrix.h;
    data = new double[w * h];
    for(int i = 0; i < w * h; i++)
        data[i] = matrix.data[i];
}

// destructor
Matrix::~Matrix() {
    delete[] data;
}

//  set/set
double Matrix::getAt(int row, int col) {
    return data[row * w + col];
}

void Matrix::setAt(int row, int col, double value) {
    data[row * w + col] = value;
}

// matrix operations
Matrix Matrix::add(Matrix& matrix) {
    if(w != matrix.w || h != matrix.h) error("Cannot add these matrices");
    Matrix sumMatrix(w, h);
    for(int i = 0; i < w * h; i++) {
        sumMatrix.data[i] = data[i] + matrix.data[i];
    }
    return sumMatrix;
}

// 2 3 4  *  2 3 1
// 2 4 1     4 5 1
//           1 1 1

// 2 x 3     3 x 3 --> 2 x 3

Matrix Matrix::multipy(Matrix& matrix) {
    if(w != matrix.h) error("Cannot multiply these matrices");
    
    Matrix res(h, matrix.w);
    for(int r = 0; r < h; r ++) {
        for(int c = 0; c < matrix.w; c++) {
            res[r][c] = 0.0;
            for(int i = 0; i < w; i++) {
                res[r][c] += getAt(r, i) * matrix.getAt(i, c);
            }
        }
    }
    return res;
}
