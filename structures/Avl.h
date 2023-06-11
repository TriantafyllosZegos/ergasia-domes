#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include "BinaryTree.h"
#include <utility>

using namespace std;

class Avl : public BinaryTree {
public:
    Avl();
    virtual void insert(const Pair<string>& value);
    //~Avl();
protected:
    NodeH* insertNode(NodeH *node,const CPair<string> &value);
    friend NodeH* rotateLeft(NodeH *n);
    friend NodeH* rotateRight(NodeH *n);
    friend int getBalance(NodeH *n);
};

#endif