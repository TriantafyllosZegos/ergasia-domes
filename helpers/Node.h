#ifndef NODE_H
#define NODE_H
#include "Pair.h"

struct Node {
    Pair<string> data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(const Pair<string> &value)
        : data(value), left(nullptr), right(nullptr) {}
    ~Node(){
        delete left;
        delete right;
    }
};
#endif