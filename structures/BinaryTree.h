#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include "../helpers/Node.h"
#include <utility>

using namespace std;

class BinaryTree {
public:
    BinaryTree();
    //~BinaryTree();
    virtual void insert(const Pair<string>& value);
    void deleteNode(Node* n);
    int search(const Pair<string>& p);
    void print();
    Node* getNode();
protected:
    Node* root;
    Node* insertNode(Node* node,const CPair<string>& value);
    int searchPair(Node* node,const CPair<string>& value);
    void print(Node* node,string tp);
    


};

#endif
