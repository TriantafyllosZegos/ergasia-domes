#ifndef NODE_H
#define NODE_H
#include <string>
#include "CPair.h"

struct Node {
    CPair<string> data;
    Node* left;
    Node* right;
    Node(){
        data = CPair<string>();
        left = nullptr;
        right = nullptr;
    }
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


struct NodeH : public Node{
    CPair<string> data;
    int height;
    NodeH* left;
    NodeH* right;
    
    
    NodeH(CPair<string> value){
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
        
    };
   /* ~Node(){
        delete left;
        delete right;
    }*/
};
#endif