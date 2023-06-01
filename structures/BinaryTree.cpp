#include "BinaryTree.h"
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Node *BinaryTree::insertNode(Node *node, CPair<string> &value)
{
    if (node == NULL)
    {
        node = new (nothrow) Node(value);
        if (node == NULL)
        {
            cout << "ERROR NODE : " << value << "MEMORY EXX";
            return node;
        }
    }
    else if (value < node->data)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insertNode(node->right, value);
    }
    else
    {
        node->data.count++;
    }
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

void BinaryTree::insert(CPair<string> &value)
{
    root = insertNode(root, value);
}

void BinaryTree::print()
{
    cout << "############## BINARY TREE ##############" << endl;
    Node *node = this->root;
    string tp = "#";
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    print(node->left, tp.append(" ❮"));

    print(node->right, tp.append(" ❯"));
}
void BinaryTree::print(Node *node, string tp)
{
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    print(node->left, tp.append(" ❮"));

    print(node->right, tp.append(" ❯"));
}

Node *BinaryTree::getNode()
{
    return root;
}
