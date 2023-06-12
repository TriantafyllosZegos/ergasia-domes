#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;


Avl::Avl():  BinaryTree(){
    root = nullptr;
};
void Avl::insert(const Pair<string> &value)
{
    cout << "before" << endl;
    root = insertNodeH((NodeH*) root, CPair<string>(value));
    cout << "after" << endl;
}


NodeH* Avl::insertNodeH(NodeH* node,const CPair<string> &pair)
{
    cout << "insertNodeH" << node << endl;
    /* 1. Perform the normal BST insertion */
    if (node == nullptr)
    {
        node = new (nothrow) NodeH(pair);
        if (node == nullptr)
        {
            cout << "ERROR NODE : " << pair << "MEMORY EXX";
            return node;
        }
    }
 
    if (pair < node->data)
        node->left = insertNodeH(node->left, pair);
    else if (pair > node->data)
        node->right = insertNodeH(node->right, pair);
    else // Equal keys are not allowed in BST
        node->data.count++;
    cout << "BEFORE HEIGHT" << node << endl;
    /* 2. Update height of this ancestor node */
    //node->height = (node->left->height >= node->right->height)?node->left->height:node->right->height + 1;
    if (node->left->height >= node->right->height){
        node->height = node->left->height;
    }else{
        node->height = node->right->height + 1;
    }
    cout << "AFTER HEIGHT" << node << endl;
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = node->getBalance();
    cout << "AFTER BALANCE" << balance << endl;
    
 
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
        node->left = node->rotateLeft();
        return node->rotateRight();
    }
 
    // Right Left Case
    if (balance < -1 && pair < node->right->data)
    {
        node->right = node->rotateRight();
        return node->rotateLeft();
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
