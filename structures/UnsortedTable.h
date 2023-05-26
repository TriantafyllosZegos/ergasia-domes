#ifndef UNSORTEDTABLE_H
#define UNSORTEDTABLE_H

#include <string>
#include "../helpers/Pair.h"
using namespace std;

class UnsortedTable {
    private:
        Pair<string>* a;
        int z;


    public:
        UnsortedTable();
        void insert(const Pair<string>& p);
        Pair<string>* get();
        void print();
};

#endif