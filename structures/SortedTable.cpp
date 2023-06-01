#include "SortedTable.h"
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

SortedTable::SortedTable(){}

SortedTable::SortedTable(Table t){}

void SortedTable::swap(int x, int y){
    Pair<string> temp = a[x];
    a[x] = a[y];
    a[y] = temp;
    
    
}

int SortedTable::partition(int low, int high, int pivotIndex){
    Pair<string> pivot = a[pivotIndex];
    swap(pivotIndex, high);
    int storeIndex = low;
    for(int i = low; i < high;i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[i], storeIndex);
            storeIndex++;
        }
    }
    swap(storeIndex, high);
    return storeIndex;
}

void SortedTable::quicksort(int low, int high){
    if (low<high)
    {
        int pivotIndex = low + (high-low)/2;
        pivotIndex = partition(low, high, pivotIndex);
        quicksort(low, pivotIndex-1);
        quicksort(pivotIndex+1, high);
    }
}

int SortedTable::search(Pair<string> pair){
    int mid = a.getSize()/2;
    int l = 0;
    int r = a.getSize();

    if (a[mid] == pair)
        return mid;

    if (a[mid] > pair)
        return searchH(l, mid-1, pair);

    if (a[mid] < pair)
        return searchH(mid+1, h, pair);

    
}
int SortedTable::searchH(int l, int h, Pair<string> pair){
    int mid = (l + h)/2;
    

    if (a[mid] == pair)
        return mid;

    if (a[mid] > pair)
        return searchH(l, mid-1, pair);

    if (a[mid] < pair)
        return searchH(mid+1, h, pair);
}













void SortedTable::sort(){

}

void SortedTable::search(const std::string& word1, const std::string& word2){
    
}

