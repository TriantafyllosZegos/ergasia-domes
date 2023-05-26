#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "../helpers/Pair.h"
#include <utility>

using namespace std;

struct Node {
    Pair<string> data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(const Pair<string>& value)
        : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;
    Node* insertNode(Node* node,Pair<string>& value);
    

public:
    BinaryTree();
    void insert(Pair<string>& value);
    void printTree(Node* node,string p);
    void printTree();
    Node* getNode ();
};

#endif
