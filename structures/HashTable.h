#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"
using namespace std;


class Hashtable{
    private:


    public:
        Hashtable(int size);

        int hashFuction(const Pair<string>&  key);

        void insert(const Pair<string>& key, int value);

        int search(const Pair<string>& key);

        void remove(const Pair<string>& key);

};






#endif