//
//  matrix.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 20.05.24.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>

class Matrix {
private:
    int w;
    int h;
    double* data;
    
public:
    Matrix(int w, int h);
    Matrix(const Matrix& matrix);
    
    double getAt(int row, int col);
    void setAt(int row, int col, double value);
    
    Matrix add(Matrix& matrix);
    Matrix multipy(Matrix& matrix);
};

#endif /* matrix_hpp */
