//
//  Sem2_2.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 29.04.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "set.h"
#include "vector.h"
#include "tokenscanner.h"


int minValueTravel(Grid<int> &costs, Vector<int> &route, Set<int> &visited, Vector<int> &resultRoute) {
    if(route.size() == costs.numCols()) {
        resultRoute = route;
        int sum = 0;
        for(int i = 0; i < route.size() - 1; i++) {
            sum += costs[route[i]][route[i + 1]];
        }
        sum += costs[route[route.size() - 1]][route[0]];
        return sum;
    }
    
    int minCost = INT_MAX;
    for(int possCity = 0; possCity < costs.numCols(); possCity ++) {
        if(!visited.contains(possCity)) {
            Vector<int> vec;
            route.add(possCity);
            visited.add(possCity);
            int currSum = minValueTravel(costs, route, visited, vec);
            if(minCost > currSum) {
                minCost = currSum;
                resultRoute = vec;
            }
            route.remove(route.size() - 1);
            visited.remove(possCity);
        }
    }
    return minCost;
}


int main() {
    Grid<int> costs(3, 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> costs[i][j];
        }
    }
    Vector<int> route;
    Set<int> visited;
    Vector<int> vec;
    cout << minValueTravel(costs, route, visited, vec) << endl;
    cout << vec << endl;
    return 0;
}
