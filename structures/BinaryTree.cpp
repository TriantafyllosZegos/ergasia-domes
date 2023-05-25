#include "BinaryTree.h"
#include <iostream>
using namespace std;

Node* BinaryTree::insertNode(Node* node, const pair<string, string>& value) {
    if (node == nullptr) {
        cout << "root: " << value.first << "," << value.second << endl;
        node = new Node(value);
    } else if (value.first < node->data.first) {
        node->left = insertNode(node->left, value);
        cout << "left: " << value.first << "," << value.second << endl;
    } else if (value.first > node->data.first) {
        node->right = insertNode(node->right, value);
        cout << "right: " << value.first << "," << value.second << endl;
    } else {
        if (value.second < node->data.second) {
            node->left = insertNode(node->left, value);
            cout << "left: " << value.first << "," << value.second << endl;
        } else {
            node->right = insertNode(node->right, value);
            cout << "right: " << value.first << "," << value.second << endl;
        }
    }
    return node;
}



BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(const pair<string, string>& value) {
    root = insertNode(root, value);
}

Node* BinaryTree::getNode() {
    return root;

}
