#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <utility>

using namespace std;

struct Node {
    pair<string, string> data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(const pair<string, string>& value)
        : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertNode(Node* node, const pair<string, string>& value);
    

public:
    BinaryTree();
    void insert(const pair<string, string>& value);
    void printInorder();
    Node* getNode ();
};

#endif
