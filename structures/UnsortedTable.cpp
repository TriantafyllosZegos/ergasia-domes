#include "UnsortedTable.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

UnsortedTable::UnsortedTable(){
    
    a = new(nothrow) Pair<string>[10000];
    if (a == NULL) cout << "UNSORTEDTABLE MEMORY ERROR" << endl;
    size = 0;
    cap = 10000;
    
}

/*
UnsortedTable::~UnsortedTable(){
    delete[] a;
    
}*/


void UnsortedTable::insert(Pair<string>& p){
    if (size == cap) {
        // If the array is full, increase its capacity
        cap += 10000;
        Pair<string>* newLines = new(nothrow) Pair<string>[cap];
        if (newLines == NULL) cout << "UNSORTEDTABLE MEMORY ERROR || size : "<< size << endl;

        // Copy the existing lines to the new array
        for (int i = 0; i < size; i++) {
                newLines[i] = a[i];
        }

        // Delete the old array
        delete[] a;

        // Update the lines pointer to point to the new array
        a = newLines;
    }

    // Store the new line
    a[size] = p;
    size++;
    

}

void UnsortedTable::print(){
    cout << "############## UNSORTED TABLE ##############" << endl;
    for (int i = 0; i < size;i++){
        cout << a[i] << endl;
    }

}

int UnsortedTable::getSize(){
    return size;
}