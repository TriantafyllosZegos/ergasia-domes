#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"

class Hashtable {
private:
    struct Node {
        Pair<string> data;
        Node* next;
        
        Node(const Pair<string>& pair) : data(pair), next(nullptr) {}
    };

    int size;
    Node** buckets;

    int hash(const Pair<string>& key);

public:
    Hashtable(int size);
    ~Hashtable();

    void insert(const Pair<string>& key);
    int search(const Pair<string>& key);
    void remove(const Pair<string>& key);
};

#endif
