#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;


Avl::Avl() : BinaryTree(){};


Node* Avl::insertNode(Node* node, CPair<string> value) {
    if (node == NULL)
    {
        node = new (nothrow) Node(value);
        if (node == NULL)
        {
            cout << "ERROR NODE : " << value << "MEMORY EXX";
            return node;
        }
    }
    else if (value < node->data)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insertNode(node->right, value);
    }
    else
    {
        node->data.count++;
    }
    return node;
}

