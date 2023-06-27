#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <utility>
#include "Table.h"

class SortedTable : public Table{
    public:
        SortedTable();
        //~SortedTable();
        long search(const Pair<string>& p);
        void insert(const Pair<string>& p);
        
    private:
        long searchPair(const Pair<string>& p,long low, long high);
        void shiftRight(long index);
        long findInsertionIndex(const Pair<string>& p,long low, long high);
        long findInsertionIndex(const Pair<string>& p);
};

#endif
