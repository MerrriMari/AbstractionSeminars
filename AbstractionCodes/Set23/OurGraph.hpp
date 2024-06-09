//
//  OurGraph.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 07.06.24.
//

#ifndef OurGraph_hpp
#define OurGraph_hpp

#include <stdio.h>
#include <stdio.h>
#include "simpio.h"
#include "iostream"
#include "console.h"
#include "set.h"

class OurGraph {
private:
    struct Vertex {
        Set<Vertex*> neighs;
    };
    Vertex* vertices;
    int vertSize;
    int edgeSize;
    bool hasPathRec(Vertex* start, Vertex* end, Set<Vertex*>& visited);
public:
    OurGraph(int size = 10);
    ~OurGraph();
    int size();
    int getEdgeSize();
    void addEdge(int a, int b);
    void removeEdge(int a, int b);
    bool hasPath(int a, int b);
};

#endif /* OurGraph_hpp */
