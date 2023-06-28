#include "SortedTable.h"
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

SortedTable::SortedTable() : Table() {
    // SortedTable constructor, calls the base class (Table) constructor
}

void SortedTable::insert(const Pair<string> &pair)
{
    checkResize();
    long insertionIndex = findInsertionIndex(pair);
    // Pair already exists, no need to insert
    if (insertionIndex == -1){ 
        return ;
    }
    // Shift the elements to the right of the insertion point
    shiftRight(insertionIndex);

    // Insert the new element at the determined position
    a[insertionIndex] = CPair(pair.first, pair.second);

    // Update the size of the array
    size++;
}

long SortedTable::findInsertionIndex(const Pair<string> &pair)
{
    return findInsertionIndex(pair, 0, (long) size - 1);
}

long SortedTable::findInsertionIndex(const Pair<string> &pair, long low, long high)
{
    while (low <= high) {
        long mid = low + (high - low) / 2;

        if (a[mid] == pair) {
            a[mid].count++;
            return -1; // Element already exists, return -1
        }
        else if (a[mid] < pair) {
            low = mid + 1; // Look in the right half of the sorted array
        }
        else {
            high = mid - 1; // Look in the left half of the sorted array
        }
    }
    return low; // Return the index where the new element should be inserted
}

void SortedTable::shiftRight(long startIndex)
{
    for (long i = (long) size - 1; i >= startIndex; i--)
    {
        a[i + 1] = a[i]; // Shift each element one position to the right
    }
}

unsigned int SortedTable::search(const Pair<string> &pair)
{
    long mid = getSize() / 2;
    long l = 0;
    long h = getSize();

    if (a[mid] > pair){
        return searchPair(pair, l, mid - 1); // Search in the left half of the sorted array
    }

    if (a[mid] < pair){
        return searchPair(pair, mid + 1, h); // Search in the right half of the sorted array
    }
    return a[mid].count; // Element found at the middle position
}

long SortedTable::searchPair(const Pair<string> &pair, long low, long high)
{
    long mid = low + (high - low) / 2;
    if (low <= high)
    {
        if (a[mid] == pair)
        {
            return a[mid].count; // Element found at the middle position
        }

        if (a[mid] > pair){
            return searchPair(pair, low, mid - 1); // Search in the left half of the remaining array
        }

        if (a[mid] < pair){
            return searchPair(pair, mid + 1, high); // Search in the right half of the remaining array
        }
    }
    return 0; // Element not found
}
