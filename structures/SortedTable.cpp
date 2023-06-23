#include "SortedTable.h"
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

SortedTable::SortedTable() : Table() {}

SortedTable::SortedTable(Table *t)
{
    this->cap = 1024;
    this->size = 0;
    this->a = t->a;
}

void SortedTable::insert(const Pair<string> &pair)
{
    checkResize();

    long insertionIndex = findInsertionIndex(pair);

    // Pair already exists
    if (insertionIndex == -1){ return ;}

    // Shift the elements to the right of the insertion point
    shiftRight(insertionIndex);

    // Insert the new element at the determined position
    a[insertionIndex] = CPair(pair.first, pair.second);

    // Update the size of the array
    size++;
}

long SortedTable::findInsertionIndex(const Pair<string> &pair, long low, long high)
{
    while (low <= high) {
        long mid = low + (high - low) / 2;

        if (a[mid] == pair) {
            a[mid].count++;
            return -1; // Element already exists
        }
        else if (a[mid] < pair) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}

long SortedTable::findInsertionIndex(const Pair<string> &pair)
{
    return findInsertionIndex(pair, 0, size - 1);
}

void SortedTable::shiftRight(long startIndex)
{
    for (long i = size - 1; i >= startIndex; i--)
    {
        a[i + 1] = a[i];
    }
}
long SortedTable::search(const Pair<string> &pair)
{
    long mid = getSize() / 2;
    long l = 0;
    long h = getSize();

    if (a[mid] > pair){
        return searchPair(pair, l, mid - 1);
    }

    if (a[mid] < pair){
        return searchPair(pair, mid + 1, h);
    }
    return a[mid].count;
}

long SortedTable::searchPair(const Pair<string> &pair, long low, long high)
{
    long mid = low + (high - low) / 2;
    if (low <= high)
    {
        if (a[mid] == pair)
        {
            return a[mid].count;
        }

        if (a[mid] > pair){
            return searchPair(pair, low, mid - 1);
        }

        if (a[mid] < pair){
            return searchPair(pair, mid + 1, high);
        }
    }
    return 0;
}
