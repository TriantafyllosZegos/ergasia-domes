#ifndef NODE_H
#define NODE_H
#include <string>
#include "CPair.h"

struct Node {
    CPair<string> data;
    Node* left;
    Node* right;
    Node(CPair<string> value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
   /* ~Node(){
        delete left;
        delete right;
    }*/
};
#endif