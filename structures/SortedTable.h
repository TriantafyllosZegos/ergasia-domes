#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <utility>
#include "Table.h"

class SortedTable : public Table{
    public:
        SortedTable();
        unsigned int search(const Pair<string>& p);
        void insert(const Pair<string>& p);
        
    private:
        unsigned int search(const Pair<string>& p,long low, long high);
        void shiftRight(long index);
        long findInsertionIndex(const Pair<string>& p,long low, long high);
        long findInsertionIndex(const Pair<string>& p);
};

#endif
