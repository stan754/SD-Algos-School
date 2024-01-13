//
// Created by stan754 on 1/12/24.
//

#include "Graph.h"

void Graph::addEdge(int X, int Y) {
    edges[X].push_back(Y);
    edges[Y].push_back(X);
}

int Graph::findShortestPath() {
    std::vector<bool> visited(n + 1, false);
    std::vector<int> distance(n + 1, -1);

    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    distance[1] = 0;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int neighbor : edges[current_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current_node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance[n];
}
