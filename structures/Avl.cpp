#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Avl::Avl() : BinaryTree(){};

void Avl::insert(const Pair<string> &value)
{
    root = insertNodeH((NodeH *)root, CPair<string>(value));
}

NodeH *Avl::insertNodeH(NodeH *node, const CPair<string> &pair)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
    {
        node = new (nothrow) NodeH(pair);
        node->data.count--;
        if (node == NULL)
        {
            cout << "ERROR NODE : " << pair << "MEMORY EXX";
            return node;
        }
    }

    if (pair < node->data)
    {
        node->left = insertNodeH(node->left, pair);
    }
    else if (pair > node->data)
    {
        node->right = insertNodeH(node->right, pair);
    }
    else
    { // Equal keys are not allowed in BST
        node->data.count++;
        return node;
    }
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // node->height = (node->left->height >= node->right->height)?node->left->height:node->right->height + 1;

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = node->getBalance();

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && pair < node->left->data)
        return node->rotateRight();

    // Right Right Case
    if (balance < -1 && pair > node->right->data)
        return node->rotateLeft();

    // Left Right Case
    if (balance > 1 && pair > node->left->data)
    {
        node->left = node->left->rotateLeft();
        return node->rotateRight();
    }

    // Right Left Case
    if (balance < -1 && pair < node->right->data)
    {
        node->right = node->right->rotateRight();
        return node->rotateLeft();
    }

    /* return the (unchanged) node pointer */
    return node;
}

int Avl::searchPair(NodeH *node, const CPair<string> &value)
{
    
    if (node == NULL)
    {
        return 0;
    }
    else if (value < node->data)
    {
        return searchPair(node->left, value);
    }
    else if (value > node->data)
    {
        return searchPair(node->right, value);
    }
    else
    {
        return node->data.count;
    }
}

// TODO: Pair < Cpair operations !!!

int Avl::search(const Pair<string> &value)
{
    NodeH * r = (NodeH*) root;
    CPair<string> v(value);
    if (r == NULL)
    {
        return 0;
    }
    else if (v < r->data)
    {
        return searchPair(r->left, v);
    }
    else if (v > root->data)
    {
        return searchPair(r->right, v);
    }
    else
    {
        return root->data.count;
    }
}

void Avl::print()
{
    cout << "############## BINARY TREE ##############" << endl;
    NodeH *node = (NodeH *)this->root;
    string tp = "#";
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    if (node->left) print(node->left, tp + " ❮");

    if (node->right) print(node->right, tp + " ❯");
}
void Avl::print(NodeH *node, string tp)
{
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    if (node->left) print(node->left, tp + " ❮");

    if (node->right) print(node->right, tp + " ❯");
}