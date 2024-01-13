//
// Created by stan754 on 1/12/24.
//

#ifndef INC_6_GRAPHS_AND_C__CONTAINERS_TREE_H
#define INC_6_GRAPHS_AND_C__CONTAINERS_TREE_H

#include <iostream>
#include <memory>

class Node {
public:
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    std::unique_ptr<Node> root;
    void addNode(std::unique_ptr<Node> &node, int X, int Y, int Z);
    int calculateDepth(std::unique_ptr<Node> &node);
public:
    void addNode(int X, int Y, int Z);
    int calculateDepth();
};

#endif //INC_6_GRAPHS_AND_C__CONTAINERS_TREE_H
