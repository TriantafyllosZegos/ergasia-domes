#include "BinaryTree.h"

Node* BinaryTree::insertNode(Node* node, const pair<string, string>& value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value.first < node->data.first) {
        node->left = insertNode(node->left, value);
    } else if (value.first > node->data.first) {
        node->right = insertNode(node->right, value);
    } else {
        cout << "Ignoring duplicate value: " << value.first << endl;
    }
    return node;
}


BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(const pair<string, string>& value) {
    root = insertNode(root, value);
}

