#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "matrix.h"

using namespace std;

int main() {
    // Create a 3x3 matrix and set some values
    Matrix mat1(3, 3);
    mat1.setAt(0, 0, 1.0);
    mat1.setAt(0, 1, 2.0);
    mat1.setAt(0, 2, 3.0);
    mat1.setAt(1, 0, 4.0);
    mat1.setAt(1, 1, 5.0);
    mat1.setAt(1, 2, 6.0);
    mat1.setAt(2, 0, 7.0);
    mat1.setAt(2, 1, 8.0);
    mat1.setAt(2, 2, 9.0);

    std::cout << "Matrix 1:" << std::endl;
    mat1.print();
    std::cout << std::endl;

    // Create another 3x3 matrix and set some values
    Matrix mat2(3, 3);
    mat2.setAt(0, 0, 9.0);
    mat2.setAt(0, 1, 8.0);
    mat2.setAt(0, 2, 7.0);
    mat2.setAt(1, 0, 6.0);
    mat2.setAt(1, 1, 5.0);
    mat2.setAt(1, 2, 4.0);
    mat2.setAt(2, 0, 3.0);
    mat2.setAt(2, 1, 2.0);
    mat2.setAt(2, 2, 1.0);

    std::cout << "Matrix 2:" << std::endl;
    mat2.print();
    std::cout << std::endl;

    // Add the two matrices
    Matrix resultAdd = mat1.add(mat2);
    std::cout << "Result of Addition:" << std::endl;
    resultAdd.print();
    std::cout << std::endl;

    // Multiply the two matrices
    Matrix resultMult = mat1.times(mat2);
    std::cout << "Result of Multiplication:" << std::endl;
    resultMult.print();
    std::cout << std::endl;

    return 0;
}
