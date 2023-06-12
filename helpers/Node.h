#ifndef NODE_H
#define NODE_H
#include <string>
#include "CPair.h"

struct Node
{
    CPair<string> data;
    Node *left;
    Node *right;
    Node()
    {
        data = CPair<string>();
        left = nullptr;
        right = nullptr;
    }
    Node(CPair<string> value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
    /* ~Node(){
         delete left;
         delete right;
     }*/
};

struct NodeH : public Node
{
    CPair<string> data;
    int height;
    NodeH *left;
    NodeH *right;

    NodeH(const CPair<string>& value)
    {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    };
    int getBalance()
    {
        if (this == NULL)
            return 0;
        return this->left->height - this->right->height;
    }
    NodeH *rotateRight()
    {
        NodeH *x = this->left;
        NodeH *T2 = x->right;

        // Perform rotation
        x->right = this;
        this->left = T2;

        // Update heights
        this->height = (this->left->height >= this->right->height) ? this->left->height : this->right->height + 1;
        x->height = (x->left->height >= x->right->height) ? x->left->height : x->right->height + 1;

        // Return new root
        return x;
    }

    NodeH *rotateLeft()
    {
        NodeH *y = this->right;
        NodeH *T2 = y->left;

        // Perform rotation
        y->left = this;
        this->right = T2;

        // Update heights
        this->height = (this->left->height >= this->right->height) ? this->left->height : this->right->height + 1;
        y->height = (y->left->height >= y->right->height) ? y->left->height : y->right->height + 1;

        // Return new root
        return y;
    }
    /* ~Node(){
         delete left;
         delete right;
     }*/
};
#endif