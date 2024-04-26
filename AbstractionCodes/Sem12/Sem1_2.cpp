//
//  Sem1_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 26.04.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "set.h"
#include "vector.h"
#include "tokenscanner.h"

bool isRightColor(Grid<bool>& graph, int currColor, Vector<int>& colorsForEachNode, int currNode) {
    for(int possNeighbour = 0; possNeighbour < colorsForEachNode.size(); possNeighbour ++) {
        if(graph[possNeighbour][currNode] && colorsForEachNode[possNeighbour] == currColor)
            return false;
    }
    return true;
}

// maxColor = 2 -- 0, 1
bool hasHamiltonCycleRec(Grid<bool>& graph, int maxColor, Vector<int>& colorsForEachNode) {
    if(maxColor >= graph.numCols()) return true;
    if(colorsForEachNode.size() == graph.numCols())
        return true;
    
    int currNode = colorsForEachNode.size();
    for(int color = 0; color < maxColor; color++) {
        if(isRightColor(graph, color, colorsForEachNode, currNode)) {
            colorsForEachNode.add(color);
            if(hasHamiltonCycleRec(graph, maxColor, colorsForEachNode)) return true;
            colorsForEachNode.remove(colorsForEachNode.size() - 1);
        }
    }
    return false;
}

int main() {
    Grid<bool> graph(4, 4);
    
    graph[0][1] = true;
    graph[1][0] = true;
    
    graph[0][2] = true;
    graph[2][0] = true;
    
    graph[2][3] = true;
    graph[3][2] = true;
    
    graph[3][1] = true;
    graph[1][3] = true;
    
    Vector<int> colors;
    
    cout << hasHamiltonCycleRec(graph, 3, colors) << endl;
    cout << colors << endl;
    return 0;
}
