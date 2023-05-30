#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include <iostream>
#include <vector>
#include <utility>

class SortedTable{
    private:
        std::vector<std::pair<std::string, std::string>> table;

    public:
        void addPair(const std::string& word1, const std::string& word2);
        void sortTable();
        void printTable();

    private:
        void quicksort(int low, int high);
        int partition(int low, int high);
};



#endif // SORTEDTABLE_H