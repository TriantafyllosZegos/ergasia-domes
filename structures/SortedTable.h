#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <utility>
#include "Table.h"

class SortedTable : public Table{
    public:
        SortedTable();
        SortedTable(Table * t);
        int search(const Pair<string>& p);
        void sort();
        
    private:
        void quicksort(int low, int high);
        int partition(int low, int high, int pivotIndex);
        int searchPair(const Pair<string>& p,int low, int high);
        void swap(int low ,int high);
};

#endif
