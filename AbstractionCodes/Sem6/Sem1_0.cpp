//
//  Sem1_0.cpp
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

void calSquareSumsForAll(Grid<int> &counts, Grid<bool> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            counts[i][j] = grid[i][j];
            if(i == 0 && j != 0) counts[i][j] += counts[i][j - 1];
            else if(i != 0 && j == 0) counts[i][j] += counts[i - 1][j];
            else if(i != 0 && j != 0)
                counts[i][j] += (counts[i - 1][j] + counts[i][j - 1] - counts[i - 1][j - 1]);
        }
    }
}

int getHintsFromGrid(Grid<int> &counts, int i, int j) {
    if(i < 0 || j < 0) return 0;
    return counts[i][j];
}

int getHintsForSingleSquare(Grid<int> &counts, int startI, int startJ, int endI, int endJ) {
    return getHintsFromGrid(counts, endI, endJ) - getHintsFromGrid(counts, startI - 1, endJ)
    - getHintsFromGrid(counts, endI, startJ - 1) + getHintsFromGrid(counts, startI - 1, startJ - 1);
}


int main() {
    Grid<bool> grid;
    grid = generatedNMineField(4, 4, 5);
    printGrid(grid);
    
    Grid<int> squareSumsForAll(4, 4);
    calSquareSumsForAll(squareSumsForAll, grid);
    printIntGrid(squareSumsForAll);
    cout << getHintsForSingleSquare(squareSumsForAll, 1, 1, 2, 2) << endl;
    return 0;
}
