//
//  Sem1_3.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 05.04.24.
//

#include <stdio.h>
#include "console.h"
#include "random.h"
#include "queue.h"
#include "grid.h"
#include "set.h"
#include <fstream>
#include "tokenscanner.h"


struct pointS {
    int i;
    int j;
    pointS(int i = 0, int j = 0) {
        this -> i = i;
        this -> j = j;
    }
};

int cmp(pointS p1, pointS p2) {
    // includes all except p1.i == p2.i
    if(p1.i < p2.i) return -1;
    if(p1.i > p2.i) return 1;
    
    // includes p1.i == p2.i and p1.j != p2.j
    if(p1.j < p2.j) return -1;
    if(p1.j > p2.j) return 1;
    
    // includes p1.i == p2.i and p1.j == p2.j
    return 0;
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

void printGrid(Grid<bool> &grid) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// always 4 neibh
Vector<pointS> getAllNeighours(pointS curr) {
    Vector<pointS> vec;
    int size = sizeof(moves) / sizeof(moves[0]);
//    cout << size << endl;
    for(int i = 0; i < size; i++) {
//        cout << curr.i + moves[i][0] << curr.j + moves[i][1] << endl;
        vec.add(pointS(curr.i + moves[i][0], curr.j + moves[i][1]));
    }
    return vec;
}

bool isValidCell(pointS pt, int limitR, int limitC) {
    return pt.i >= 0 && pt.i < limitR && pt.j >= 0 && pt.j < limitC;
}

bool isBlocked(pointS pt, Grid<bool> &grid) {
    return grid[pt.i][pt.j];
}

bool isFreePath(Grid<bool> &grid, pointS start, pointS end) {
    Queue<pointS> que;
    Set<pointS> visited(cmp);
    
    que.enqueue(start);
    visited.add(start);
    
    while (!que.isEmpty()) {
        pointS curr = que.dequeue();
        if(cmp(curr, end) == 0)
            return true;
        Vector<pointS> neibs = getAllNeighours(curr);
        for(pointS nb : neibs) {
//            cout <<nb.i << nb.j << endl;
            
            if(isValidCell(nb, grid.numRows(), grid.numCols()) && !isBlocked(nb, grid) &&!visited.contains(nb)) {
//                cout <<nb.i << nb.j << endl;
                que.enqueue(nb);
                visited.add(nb);
            }
        }
    }
    return false;
}

int main() {
    Grid<bool> grid;
    grid = generatedNMineField(4, 4, 3);
    printGrid(grid);
    cout << isFreePath(grid, pointS(0, 0), pointS(3, 3)) << endl;
    return 0;
}
