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
        //void sort();
        
    private:
        //void quicksort(long low, long high);
        //long partition(long low, long high, long pivotIndex);
        long searchPair(const Pair<string>& p,long low, long high);
        //void insertPair(const Pair<string>& p,int low, int high);
        void shiftRight(long index);
        long findInsertionIndex(const Pair<string>& p,long low, long high);
        long findInsertionIndex(const Pair<string>& p);
        //void swap(long low ,long high);
};

#endif
