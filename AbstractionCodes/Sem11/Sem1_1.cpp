//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 19.04.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include <fstream>
#include "tokenscanner.h"

// 2
bool isLinkWithAll(Grid<bool> &grid, Vector<int> graph, int curr) {
    for(int i = 0; i < graph.size(); i++) {
        if(!grid[curr][graph[i]]) {
            return false;
        }
    }
    return true;
}

bool isClique(Grid<bool> &grid, Vector<int> graph) {
    if(graph.size() <= 1) return true;
    int curr = graph[graph.size() - 1];
//    cout << "graph" << graph << endl;
    graph.remove(graph.size() - 1);
//    cout << graph << endl;
    return isLinkWithAll(grid, graph, curr) && isClique(grid, graph);
}

int maxClique(Grid<bool> &grid, Vector<int> &currSet, int curr) {
    if(curr == -1) {
        if(isClique(grid, currSet)) {
//            cout << "is clique" << currSet << endl;
            return currSet.size() ;
        }
        else return -1;
    }
    
    // left side
    int maxCliequeWithoutCurr = maxClique(grid, currSet, curr - 1);
    currSet.add(curr);
    // right side
    int maxCliequeWithCurr = maxClique(grid, currSet, curr - 1);
    currSet.remove(currSet.size() - 1);
    // max(left, right)
    return max(maxCliequeWithoutCurr, maxCliequeWithCurr);
}

int maxCliqueWrapper(Grid<bool> &grid) {
    Vector<int> maxSet;
    return maxClique(grid, maxSet, grid.numCols() - 1);
}

int main() {
    Grid<bool> grid(5, 5);
    grid[2][4] = true;
    grid[3][4] = true;
    grid[4][2] = true;
    grid[4][3] = true;
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            grid[i][j] = grid[i][j] ? false : true;
        }
    }
    Vector<int> vec;
    vec.add(0);
    vec.add(1);
    vec.add(2);
    vec.add(3);
//    vec.add(4);

    cout << grid << endl;
    cout << isClique(grid, vec) << endl;
    cout << maxCliqueWrapper(grid) << endl;
    return 0;
}
