//
//  Sem2_0.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 29.03.24.
//

#include <stdio.h>
#include <stdio.h>
#include "console.h"
#include "random.h"
#include "grid.h"
#include <fstream>
#include "tokenscanner.h"

void printGrid(Grid<bool> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printIntGrid(Grid<int> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Grid<bool> generatedNMineField(int n, int m, int nMines) {
    Grid<bool> grid(n, m);
    int i, j;
    while(nMines > 0) {
        i = randomInteger(0, n - 1);
        j = randomInteger(0, m - 1);
        if(grid[i][j]) continue;
        
        grid[i][j] = true;
        nMines--;
    }
    return grid;
}

Grid<int> trimBackToSize(Grid<int> &grid) {
    Grid<int> gridTrimmed(grid.numRows() - 1, grid.numCols() - 1);
    for(int i = 1; i < grid.numRows(); i++) {
        for(int j = 1; j < grid.numCols(); j++) {
            gridTrimmed[i - 1][j - 1] = grid[i][j];
        }
    }
    return gridTrimmed;
}

Grid<int> calcSquareSums(Grid<bool> &grid) {
    Grid<int> squareSums(grid.numRows() + 1, grid.numCols() + 1);
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            squareSums[i + 1][j + 1] = grid[i][j] +
            squareSums[i + 1][j] + squareSums[i][j + 1] - squareSums[i][j];
        }
    }
    return trimBackToSize(squareSums);
}


int main() {
    Grid<bool> grid;
    grid = generatedNMineField(4, 4, 5);
    printGrid(grid);
    Grid<int> sums = calcSquareSums(grid);
    printIntGrid(sums);
    return 0;
}
