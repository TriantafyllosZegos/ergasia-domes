#include "BinaryTree.h"
#include "../helpers/Pair.h"
#include <iostream>
using namespace std;

Node* BinaryTree::insertNode(Node* node, Pair<string>& value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value.getFirst() < node->data.getFirst()) {
        node->left = insertNode(node->left, value);
        
    } else {
        node->right = insertNode(node->right, value);
        
    } 
    return node;
}



BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(Pair<string>& value) {
    root = insertNode(root, value);
}

void BinaryTree::printTree()
{
    Node* node = this->root;
    string p = "#";
    if (node == nullptr)
        return;
    
    cout << p << " : " << node->data << endl;

    printTree(node->left,p.append(" ❮"));

    printTree(node->right,p.append(" ❯"));
}
void BinaryTree::printTree(Node* node,string p)
{
    if (node == nullptr)
        return;
    
    cout << p << " : " << node->data << endl;

    printTree(node->left,p.append(" ❮"));

    printTree(node->right,p.append(" ❯"));
}

Node* BinaryTree::getNode() {
    return root;

}
