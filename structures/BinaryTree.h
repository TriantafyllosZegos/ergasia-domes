#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <utility>

using namespace std;

class BinaryTree {
private:
    Node* root;
    Node* insertNode(Node* node,Pair<string>& value);
    

public:
    BinaryTree();
    void insert(Pair<string>& value);
    int search(Pair<string>& p);
    void print(Node* node,string tp);
    void print();
    Node* getNode ();
};

#endif
