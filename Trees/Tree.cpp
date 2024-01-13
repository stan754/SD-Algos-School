//
// Created by stan754 on 1/12/24.
//

#include "Tree.h"

#include <memory>

void Tree::addNode(std::unique_ptr<Node> &node, int X, int Y, int Z) {
    if (node == nullptr) {
        node = std::make_unique<Node> (X);
    }

    if (node->value == X) {
        if (node->left == nullptr) {
            if (Y != 0) {
                node->left = std::make_unique<Node> (Y);
            }
        }
        if (node->right == nullptr) {
            if (Z != 0) {
                node->right = std::make_unique<Node> (Z);
            }
        }
    } else {
        if (node->left != nullptr) {
            addNode(node->left, X, Y, Z);
        }
        if (node->right != nullptr) {
            addNode(node->right, X, Y, Z);
        }
    }
}

int Tree::calculateDepth(std::unique_ptr<Node> &node) {
    if (node == nullptr) {
        return 0;
    }

    int left = calculateDepth(node->left);
    int right = calculateDepth(node->right);

    return std::max(left, right) + 1;
}

void Tree::addNode(int X, int Y, int Z) {
    addNode(root, X, Y, Z);
}

int Tree::calculateDepth() {
    return calculateDepth(root);
}


