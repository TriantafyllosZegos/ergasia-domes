#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"
#include "../helpers/Structure.h"
#include "../helpers/HashItem.h"


class HashTable : public Structure {
private: 
    HashItem<string> * a;
    unsigned long hash(const Pair<string>& key);
    unsigned long cap;
    unsigned long numElements;

    

public:
    HashTable();
    virtual ~HashTable();
    unsigned long getSize();
    void insert(const Pair<string>& key);
    void resize();
    unsigned int search(const Pair<string>& key);
    void print();
};

#endif
