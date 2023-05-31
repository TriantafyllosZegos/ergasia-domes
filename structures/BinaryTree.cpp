#include "BinaryTree.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Node* BinaryTree::insertNode(Node* node, Pair<string> value) {
    if (node == NULL) {
        node = new(nothrow) Node(value);
        if (node == NULL){
            cout << "ERROR NODE : " << value << "MEMORY EXX";
            return node;
        }
    } else if (value.first <= node->data.first) {
        node->left = insertNode(node->left, value);
        
    } else if (value.first > node->data.first) {
        node->right = insertNode(node->right, value);
        
    } /*else {
        if (value.second < node->data.second) {
        node->left = insertNode(node->left, value);
        
        } else if (value.second > node->data.second) {
        node->right = insertNode(node->right, value);
        
        }else {
        node->data.increaseCount(1);
        }
        
    }*/
    return node;
}



BinaryTree::BinaryTree() : root(nullptr) {}

/*
void BinaryTree::deleteNode(Node* n){
    if (n == nullptr)
        return;
    delete n->left;
    delete n->right;

    //deleteNode(n->left);
    //deleteNode(n->right);

}

BinaryTree::~BinaryTree(){
    deleteNode(root);
}*/


void BinaryTree::insert(Pair<string> value) {
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
