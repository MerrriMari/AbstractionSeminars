//
//  Main.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 07.06.24.
//

#include <stdio.h>
#include "OurGraph.hpp"
#include <stdio.h>
#include "simpio.h"
#include "iostream"
#include "console.h"

using namespace std;

int main() {
    OurGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(4, 3);
    cout << graph.getEdgeSize() << endl;
    cout << graph.hasPath(0, 3) << endl;
    cout << graph.hasPath(0, 4) << endl;
    cout << endl;
    return 0;
}
