#ifndef UNSORTEDTABLE_H
#define UNSORTEDTABLE_H

#include <string>
#include "../helpers/Pair.h"
using namespace std;

class UnsortedTable {
    private:
        Pair<string>* a;
        long int size;


    public:
        UnsortedTable();
        //~UnsortedTable();
        void insert(Pair<string>& p);
        void print();
        int getSize();
};

#endif