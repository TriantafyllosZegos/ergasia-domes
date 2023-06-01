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
    //~Avl();
protected:
    Node* insertNode(Node *node, Pair<string> value);
};

#endif