#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"
using namespace std;


class Hashtable{
    private:
        int hash(const Pair<string>&  key);
        int size;
        vector<vector<Pair<string>>> buckets;
        
    public:
        Hashtable(int size);

        void insert(const Pair<string>& key);

        int search(const Pair<string>& key);

        void remove(const Pair<string>& key);

};



       




#endif