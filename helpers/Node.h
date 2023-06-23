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

    NodeH(const CPair<string> &value)
    {
        data = value;
        height = 1;
        left = NULL;
        right = NULL;
    };
    friend int getBalance(NodeH *N)
    {
        if (N == nullptr)
            return 0;
        return getHeight(N->left) - getHeight(N->right);
    }
    friend int getHeight(NodeH *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    };
    friend int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    NodeH *rotateRight()
    {
        NodeH *x = this->left;
        NodeH *T2 = x->right;

        // Perform rotation
        x->right = this;
        this->left = T2;

        // Update heights
        this->height = max(getHeight(this->left),getHeight(this->right)) + 1;
        x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

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
        this->height = max(getHeight(this->left),getHeight(this->right)) + 1;
        y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

        // Return new root
        return y;
    }
    /* ~Node(){
         delete left;
         delete right;
     }*/
};
#endif