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
        // Create a new node with the given value if the current node is null
        node = new (nothrow) Node(value);
        if (node == NULL)
        {
            // Check if memory allocation was successful
            cout << "ERROR NODE : " << value << "MEMORY EXX";
            return node;
        }
    }
    else if (value < node->data)
    {
        // Recursively insert the value into the left subtree if it is smaller than the current node's value
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data)
    {
        // Recursively insert the value into the right subtree if it is greater than the current node's value
        node->right = insertNode(node->right, value);
    }
    else
    {
        // If the value is equal to the current node's value, increment the count
        node->data.count++;
    }
    return node;
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree(){
    // Destructor to deallocate the memory used by the binary tree
    delete root;
}

void BinaryTree::insert(const Pair<string> &value)
{
    // Insert a pair into the binary tree
    root = insertNode(root, CPair<string>(value));
}

int BinaryTree::search(Node *node, const CPair<string> &value)
{
    if (node == NULL)
    {
        // Base case: Reached a null node, value not found
        return 0;
    }
    else if (value < node->data)
    {
        // Recursively search in the left subtree if the value is smaller than the current node's value
        return search(node->left, value);
    }
    else if (value > node->data)
    {
        // Recursively search in the right subtree if the value is greater than the current node's value
        return search(node->right, value);
    }
    else
    {
        // Value found, return the count of occurrences
        return node->data.count;
    }
}

int BinaryTree::search(const Pair<string> &value)
{
    // Search for a pair in the binary tree
    CPair<string> v(value);
    if (root == NULL)
    {
        // If the root is null, tree is empty, value not found
        return 0;
    }
    else if (v < root->data)
    {
        // Recursively search in the left subtree if the value is smaller than the root's value
        return search(root->left, v);
    }
    else if (v > root->data)
    {
        // Recursively search in the right subtree if the value is greater than the root's value
        return search(root->right, v);
    }
    else
    {
        // Value found at the root, return the count of occurrences
        return root->data.count;
    }
}

void BinaryTree::print()
{
    // Print the binary tree in an organized manner
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
    // Recursive helper function to print the binary tree
    if (node == nullptr)
        return;

    cout << tp << " : " << node->data << endl;
    if (node->left) print(node->left, tp.append(" ❮"));

    if (node->right) print(node->right, tp.append(" ❯"));
}

Node *BinaryTree::getNode()
{
    // Get the root node of the binary tree
    return root;
}
