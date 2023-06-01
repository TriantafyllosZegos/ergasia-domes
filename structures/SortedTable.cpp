#include "SortedTable.h"
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

SortedTable::SortedTable() {}

SortedTable::SortedTable(Table t)
{
    a = t.a;
}

void SortedTable::swap(int x, int y)
{
    Pair<string> temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int SortedTable::partition(int low, int high, int pivotIndex)
{
    Pair<string> pivot = a[pivotIndex];
    swap(pivotIndex, high);
    int storeIndex = low;
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(i, storeIndex);
            storeIndex++;
        }
    }
    swap(storeIndex, high);
    return storeIndex;
}

void SortedTable::quicksort(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = low + (high - low) / 2;
        pivotIndex = partition(low, high, pivotIndex);
        quicksort(low, pivotIndex - 1);
        quicksort(pivotIndex + 1, high);
    }
}
void SortedTable::sort()
{
    quicksort(0, size);
}

int SortedTable::search(const Pair<string> &pair)
{
    int counter = 0;
    int mid = getSize() / 2;
    int l = 0;
    int h = getSize();

    if (a[mid] == pair)
    {
        counter++;
        int index = mid + 1;
        while (0 <= index < size && a[index] == pair)
        {
            counter++;
            index++;
        }
        index = mid - 1;
        while (0 <= index < size && a[index] == pair)
        {
            counter++;
            index--;
        }
        return counter;
    }

    if (a[mid] > pair)
        return searchPair(pair,l, mid - 1);

    if (a[mid] < pair)
        return searchPair(pair,mid + 1, h);
}
int SortedTable::searchPair(const Pair<string> &pair,int low, int high)
{
    int mid = low + (high - low) / 2;
    if (low <= high)
    {
        if (a[mid] == pair)
        {
            int counter = 1;
            int index = mid + 1;
            while (0 <= index < size && a[index] == pair)
            {
                counter++;
                index++;
            }
            index = mid - 1;
            while (0 <= index < size && a[index] == pair)
            {
                counter++;
                index--;
            }
            return counter;
        }

        if (a[mid] > pair)
            return searchPair(pair,low, mid - 1);

        if (a[mid] < pair)
            return searchPair(pair,mid + 1, high);
    }
    return 0;
}
