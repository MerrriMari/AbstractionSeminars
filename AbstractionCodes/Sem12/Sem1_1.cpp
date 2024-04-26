//
//  Sem1_1.cpp
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

bool hasHamiltonCycleRec(Grid<bool>& graph, Vector<int>& cycle, Set<int>& visitedNodes) {
    if(cycle.size() == graph.numCols()) {
        int v1 = cycle[0];
        int v2 = cycle[cycle.size() - 1];
        return graph[v2][v1];
    }
    
    // i is nextnode
    for(int i = 0; i < graph.numCols(); i++) {
        if(!visitedNodes.contains(i)) {
            if(cycle.isEmpty() || graph[cycle[cycle.size() - 1]][i]) {
                visitedNodes.add(i);
                cycle.add(i);
                // rec
                if(hasHamiltonCycleRec(graph, cycle, visitedNodes))
                    return true;
                visitedNodes.remove(i);
                cycle.remove(cycle.size() - 1);
            }
        }
    }
    return false;
}

bool hasHamiltonCycle(Grid<bool>& graph, Vector<int>& cycle) {
    Set<int> visitedNodes;
    return hasHamiltonCycleRec(graph, cycle, visitedNodes);
}


int main() {
    Grid<bool> graph(4, 4);
    
    graph[0][1] = true;
    graph[1][0] = true;
    
    graph[0][2] = true;
//    graph[2][0] = true;
    
    graph[2][3] = true;
    graph[3][2] = true;
    
    graph[3][1] = true;
    graph[1][3] = true;
    
    Vector<int> cycle;
    cout << hasHamiltonCycle(graph, cycle) << endl;
    cout << cycle << endl;
    return 0;
}
