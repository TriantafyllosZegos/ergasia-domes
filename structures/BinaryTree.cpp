#include "BinaryTree.h"
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Node *BinaryTree::insertNode(Node *node, const CPair<string> &value)
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

void BinaryTree::insert(const Pair<string> &value)
{
    root = insertNode(root, CPair<string>(value));
}

int BinaryTree::search(Node *node, const CPair<string> &value)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (value < node->data)
    {
        return search(node->left, value);
    }
    else if (value > node->data)
    {
        return search(node->right, value);
    }
    else
    {
        return node->data.count;
    }
}

//TODO: Pair < Cpair operations !!!

int BinaryTree::search(const Pair<string> &value)
{
    CPair<string> v(value);
    if (root == NULL)
    {
        return 0;
    }
    else if (v < root->data)
    {
        return search(root->left, v);
    }
    else if (v > root->data)
    {
        return search(root->right, v);
    }
    else
    {
        return root->data.count;
    }
}

void BinaryTree::print()
{
    cout << "############## BINARY TREE ##############" << endl;
    Node *node = this->root;
    string tp = "#";
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    if (node->left) print(node->left, tp + " ❮");

    if (node->right) print(node->right, tp + " ❯");
}
void BinaryTree::print(Node *node, string tp)
{
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;
    if (node->left) print(node->left, tp.append(" ❮"));

    if (node->right) print(node->right, tp.append(" ❯"));
}

Node *BinaryTree::getNode()
{
    return root;
}
