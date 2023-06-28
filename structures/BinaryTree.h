#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <utility>

#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include "../helpers/Node.h"
#include "../helpers/Structure.h"

using namespace std;

class BinaryTree : public Structure {
public:
    BinaryTree();
    virtual ~BinaryTree();
    virtual void insert(const Pair<string>& value);
    //void deleteNode(Node* n);
    virtual unsigned int search(const Pair<string>& p);
    virtual void print();
    Node* getNode();
protected:
    Node* root;
    Node* insertNode(Node* node,const CPair<string>& value);
    int search(Node* node,const CPair<string>& value);
    void print(Node* node,string tp);
    


};

#endif
