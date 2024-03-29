//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 25.03.24.
//

#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "random.h"

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

void setMines(Grid<bool> &grid, double prob) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            // row - i  column - j
            grid[i][j] = randomChance(prob);
        }
    }
}

void setNMines(Grid<bool> &grid, int n) {
    if(n > grid.numRows() * grid.numCols()) return;
    while(n > 0) {
        int i = randomInteger(0, grid.numRows() - 1); // row i
        int j = randomInteger(0, grid.numCols() - 1); // col j
        if(grid[i][j]) continue;
        grid[i][j] = true;
        n--;
    }
}

bool isValidCell(int i, int j, int maxI, int maxJ) {
    return i >= 0 && i < maxI && j >= 0 && j < maxJ;
}

int getMinesForOneSquare(int centerI, int centerJ, Grid<bool> &grid) {
    if(grid[centerI][centerJ]) return -1;
    int sum = 0;
    for(int i = centerI - 1; i <= centerI + 1; i ++) {
        for(int j = centerJ - 1; j <= centerJ + 1; j ++) {
            if(isValidCell(i, j, grid.numRows(), grid.numCols()))
                sum += grid[i][j];
        }
    }
    return sum;
}

void countSquareHints(Grid<int> &counts, Grid<bool> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            // 3 x 3 center coordiantes i, j
            counts[i][j] = getMinesForOneSquare(i, j, grid);
        }
    }
}

int main() {
    Grid<bool> grid(4, 4);
    setMines(grid, 0.5);
    printGrid(grid);
    Grid<bool> gridForNMines(4, 4);
    setNMines(gridForNMines, 5);
    printGrid(gridForNMines);
    Grid<int> squareMinesCount(4, 4);
    countSquareHints(squareMinesCount, gridForNMines);
    printIntGrid(squareMinesCount);
    return 0;
}
