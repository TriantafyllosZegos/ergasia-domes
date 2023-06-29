#ifndef HASHITEM_H
#define HASHITEM_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"
#include "../helpers/Structure.h"

template<typename T> 
struct HashItem
{
    Pair<T> key;
    int value;
    HashItem()
    {
        key = Pair<T>();
        value = 0;
    }
    HashItem(const Pair<T>& pair)
    {
        key = pair;
        value = 1;
    }
};

#endif
