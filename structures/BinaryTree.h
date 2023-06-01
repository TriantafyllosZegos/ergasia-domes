#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include "../helpers/Node.h"
#include <utility>

using namespace std;

class BinaryTree {
protected:
    Node* root;
    virtual Node* insertNode(Node* node,CPair<string>& value);
    

public:
    BinaryTree();
    //~BinaryTree();
    void insert(CPair<string>& value);
    void deleteNode(Node* n);
    int search(CPair<string> p);
    void print(Node* node,string tp);
    void print();
    Node* getNode();
};

#endif
