#include "BinaryTree.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Node* BinaryTree::insertNode(Node* node, Pair<string>& value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value.getFirst() <= node->data.getFirst()) {
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

void BinaryTree::print()
{
    cout << "############## BINARY TREE ##############" << endl;
    Node* node = this->root;
    string tp = "#";
    if (node == nullptr)
        return;
    
    cout << tp << " : " << node->data << endl;

    print(node->left,tp.append(" ❮"));

    print(node->right,tp.append(" ❯"));
}
void BinaryTree::print(Node* node,string tp)
{
    if (node == nullptr)
        return;
    
    cout << tp << " : " << node->data << endl;

    print(node->left,tp.append(" ❮"));

    print(node->right,tp.append(" ❯"));
}

Node* BinaryTree::getNode() {
    return root;

}
