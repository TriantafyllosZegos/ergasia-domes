#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Avl::Avl() : BinaryTree() {};

void Avl::insert(const Pair<string> &value)
{
    // Insert a pair into the AVL tree
    root = insertNodeH((NodeH *)root, CPair<string>(value));
}

NodeH *Avl::insertNodeH(NodeH *node, const CPair<string> &pair)
{
    // Perform the normal BST insertion 
    if (node == NULL)
    {
        // Create a new node with the given pair if the current node is null
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
        // Recursively insert the pair into the left subtree if it is smaller than the current node's pair
        node->left = insertNodeH(node->left, pair);
    }
    else if (pair > node->data)
    {
        // Recursively insert the pair into the right subtree if it is greater than the current node's pair
        node->right = insertNodeH(node->right, pair);
    }
    else
    { // Equal keys are not allowed in BST
        // If the pair is equal to the current node's pair, increment the count
        node->data.count++;
        return node;
    }
    //  Update height of this ancestor node 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    /* Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

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

    // return the (unchanged) node pointer 
    return node;
}

int Avl::searchPair(NodeH *node, const CPair<string> &value)
{
    // Search for a pair in the AVL tree
    if (node == NULL)
    {
        return 0;
    }
    else if (value < node->data)
    {
        // Recursively search in the left subtree if the value is smaller than the current node's pair
        return searchPair(node->left, value);
    }
    else if (value > node->data)
    {
        // Recursively search in the right subtree if the value is greater than the current node's pair
        return searchPair(node->right, value);
    }
    else
    {
        // Pair found, return the count of occurrences
        return node->data.count;
    }
}

unsigned int Avl::search(const Pair<string> &value)
{
    // Search for a pair in the AVL tree
    NodeH *r = (NodeH *)root;
    CPair<string> v(value);
    if (r == NULL)
    {
        return 0;
    }
    else if (v < r->data)
    {
        // Recursively search in the left subtree if the value is smaller than the root's pair
        return searchPair(r->left, v);
    }
    else if (v > root->data)
    {
        // Recursively search in the right subtree if the value is greater than the root's pair
        return searchPair(r->right, v);
    }
    else
    {
        // Pair found at the root, return the count of occurrences
        return root->data.count;
    }
}

void Avl::print()
{
    cout << "############## AVL ##############" << endl;
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
    // Recursive helper function to print the AVL tree
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;

    if (node->left) print(node->left, tp + " ❮");

    if (node->right) print(node->right, tp + " ❯");
}
