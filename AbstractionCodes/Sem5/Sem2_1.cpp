//
//  Sem2_1.cpp
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

Grid<bool> generatedMineField(int n, int m, double prob) {
    Grid<bool> grid(n, m);
    // rows
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            grid[i][j] = randomChance(prob); // 0.3 - true; 0.7 - false
        }
    }
    return grid;
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

int calcThreeThreeSum(int centerI, int centerJ, Grid<bool> &grid) {
    if(grid[centerI][centerJ]) return -1;
    int startI = max(centerI - 1, 0);
    int endI = min(centerI + 1, grid.numRows() - 1);
    int startJ = max(centerJ - 1, 0);
    int endJ = min(centerJ + 1, grid.numCols() - 1);
    int sum = 0;
    for(int i = startI; i <= endI; i++) {
        for(int j = startJ; j <= endJ; j++) {
            sum += grid[i][j];
        }
    }
    return sum;
}

void calculateThreeThreeSumGrid(Grid<int> &result, Grid<bool> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            result[i][j] = calcThreeThreeSum(i, j, grid);
        }
    }
}

int main() {
    Grid<bool> grid = generatedMineField(4, 4, 0.5);
    printGrid(grid);
    grid = generatedNMineField(4, 4, 5);
    printGrid(grid);
    Grid<int> threeThreeSq(4, 4);
    calculateThreeThreeSumGrid(threeThreeSq, grid);
    printIntGrid(threeThreeSq);
    return 0;
}
