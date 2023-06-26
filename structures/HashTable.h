#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"


struct HashItem
{
    Pair<string> key;
    int value;
    HashItem()
    {
        key = Pair<string>();
        value = 0;
    }
    HashItem(const Pair<string>& pair)
    {
        key = pair;
        value = 1;
    }
};

class HashTable {
private:
    HashItem * a;
    unsigned long hash(const Pair<string>& key);
    unsigned long cap;
    unsigned long numElements;

    

public:
    HashTable();
    //~HashTable();
    unsigned long getSize();
    void insert(const Pair<string>& key);
    void resize();
    int search(const Pair<string>& key);
    void remove(const Pair<string>& key);
};

#endif
