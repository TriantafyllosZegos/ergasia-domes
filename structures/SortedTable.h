/*#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <utility>
#include "structures/Table.h"

class SortedTable : public Table{
    public:
        SortedTable();
        SortedTable(Table t);
        void search(const std::string& word1, const std::string& word2);
        void sort();

    private:
        void quicksort(int low, int high);
        int partition(int low, int high);
        void swap(int low ,int high);
};



#endif // SORTEDTABLE_H
*/