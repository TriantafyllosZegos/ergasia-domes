#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include "BinaryTree.h"
#include <utility>

using namespace std;

class Avl : public BinaryTree
{
public:
    Avl();
    void insert(const Pair<string> &value);
    unsigned int search(const Pair<string>& p);
    void print();
protected:
    NodeH *insertNodeH(NodeH *node, const CPair<string> &value);
    int search(NodeH* node,const CPair<string>& value);
    void print(NodeH* node,string tp);
    
};

#endif