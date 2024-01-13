//
// Created by stan754 on 1/12/24.
//

#ifndef INC_6_GRAPHS_AND_C__CONTAINERS_GRAPH_H
#define INC_6_GRAPHS_AND_C__CONTAINERS_GRAPH_H

#include <vector>
#include <queue>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> edges;

public:
    Graph(int n) : n(n), edges(n+1) {}
    void addEdge(int X, int Y);
    int findShortestPath();
};


#endif //INC_6_GRAPHS_AND_C__CONTAINERS_GRAPH_H
