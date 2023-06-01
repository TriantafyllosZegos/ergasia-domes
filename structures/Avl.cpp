#include "Avl.h"
#include "../helpers/Pair.h"
#include "../helpers/Node.h"
#include <iostream>
using namespace std;

Node* Avl::insertNode(Node *node, Pair<string> value)
{
    if (node == NULL)
    {
        node = new (nothrow) Node(value);
        if (node == NULL)
        {
            cout << "ERROR NODE : " << value << "MEMORY EXX";
            return node;
        }
    }
    else if (value.first <= node->data.first)
    {
        node->left = insertNode(node->left, value);
    }
    else
    {
        node->right = insertNode(node->right, value);

        return node;
    }
};

Avl::Avl() : BinaryTree(){};