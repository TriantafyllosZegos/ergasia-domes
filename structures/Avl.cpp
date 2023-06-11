#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;


Avl::Avl():  BinaryTree(){
    root = nullptr;
};


NodeH *rotateRight(NodeH *y)
{
    NodeH *x = y->left;
    NodeH *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = (y->left->height >= y->right->height)?y->left->height:y->right->height + 1;
    x->height = (x->left->height >= x->right->height)?x->left->height:x->right->height + 1;
 
    // Return new root
    return x;
}

NodeH *rotateLeft(NodeH *x)
{
    NodeH *y = x->right;
    NodeH *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = (x->left->height >= x->right->height)?x->left->height:x->right->height + 1;
    y->height = (y->left->height >= y->right->height)?y->left->height:y->right->height + 1;
 
    // Return new root
    return y;
}

int getBalance(NodeH *n)
{
    if (n == NULL)
        return 0;
    return n->left->height - n->right->height;
}
void Avl::insert(const Pair<string> &value)
{
    root = insertNode((NodeH*) root, CPair<string>(value));
}
NodeH* insertNode(NodeH* node,const CPair<string> &pair)
{
    /* 1. Perform the normal BST insertion */
    cout << node->height << endl;
    if (node == NULL)
    {
        node = new (nothrow) NodeH(pair);
        if (node == NULL)
        {
            cout << "ERROR NODE : " << pair << "MEMORY EXX";
            return node;
        }
    }
 
    if (pair < node->data)
        node->left = insertNode(node->left, pair);
    else if (pair > node->data)
        node->right = insertNode(node->right, pair);
    else // Equal keys are not allowed in BST
        node->data.count++;
 
    /* 2. Update height of this ancestor node */
    node->height = (node->left->height >= node->right->height)?node->left->height:node->right->height + 1;
    
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
    
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && pair < node->left->data)
        return rotateRight(node);
 
    // Right Right Case
    if (balance < -1 && pair > node->right->data)
        return rotateLeft(node);
 
    // Left Right Case
    if (balance > 1 && pair > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
 
    // Right Left Case
    if (balance < -1 && pair < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
