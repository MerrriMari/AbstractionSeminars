//
//  OurGraph.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 07.06.24.
//

#include "OurGraph.hpp"
#include <stdio.h>
#include "simpio.h"
#include "iostream"
#include "console.h"
#include "set.h"

using namespace std;

OurGraph::OurGraph(int size) {
    vertSize = size;
    edgeSize = 0;
    vertices = new Vertex[size];
}
OurGraph::~OurGraph() {
    delete[] vertices;
}
int OurGraph::size() {
    return vertSize;
}
int OurGraph::getEdgeSize() {
    return edgeSize;
}
void OurGraph::addEdge(int a, int b) {
    if(isValidIndex(a) && isValidIndex(a))
    vertices[a].neighs.add(vertices + b);
    edgeSize ++;
    // vertices[a] --> *(vertices + a)
}
void OurGraph::removeEdge(int a, int b) {
    vertices[a].neighs.remove(vertices + b);
    edgeSize --;
}

bool OurGraph::hasPathRec(Vertex* start, Vertex* end, Set<Vertex*>& visited) {
    if(start == end)
        return true;
    visited.add(start);
    for(Vertex* curr : start -> neighs) {
        if(!visited.contains(curr)) {
            if(hasPathRec(curr, end, visited))
                return true;
        }
    }
//    visited.remove(start);
    return false;
}

bool OurGraph::hasPath(int a, int b) {
    Set<Vertex*> visited;
    return hasPathRec(vertices + a, vertices + b, visited);
}
