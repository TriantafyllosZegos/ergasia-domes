#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <utility>
#include "Table.h"

class SortedTable : public Table{
    public:
        SortedTable();
        SortedTable(Table t);
        int search(Pair<string> key);
        void sort();
        
    private:
        void quicksort(int low, int high);
        int partition(int low, int high, int pivotIndex);
        int searchH(int l, int h);
        void swap(int low ,int high);
};



#endif // SORTEDTABLE_H
