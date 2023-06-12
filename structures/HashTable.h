#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"

class HashTable {
private:
    struct Node {
        Pair<string> data;
        int count;
        Node* next;

        Node(const Pair<string>& pair) : data(pair),count(1), next(nullptr) {}
    };

    int size;
    Node** buckets;

    int hash(const Pair<string>& key);

    

public:
    HashTable(int size);
    ~HashTable();

    void insert(const Pair<string>& key);
    int search(const Pair<string>& key);
    void remove(const Pair<string>& key);
};

#endif
