#include "Table.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

Table::Table(){
    this->cap = 50000000;
    this->size = 0;
    a = new(nothrow) Pair<string>[cap]();
    if (a == NULL) cout << "TABLE MEMORY ERROR" << endl;
    
    
    
}


Table::~Table(){
    delete[] a;
    
}

void Table::insert(const Pair<string>& p){
    
    if (size == cap) {
        // If the array is full, increase its capacity
        this->cap += 50000000;
        Pair<string> * newLines = new(nothrow) Pair<string>[cap]();
        if (newLines == NULL) cout << "Table MEMORY ERROR || size : " << size << endl;

        // Copy the existing lines to the new array
        for (unsigned int i = 0; i < size; i++) {
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


void Table::print(){
    cout << "############## TABLE ##############" << endl;
    for (unsigned int i = 0; i < size;i++){
        cout << a[i] << endl;
    }
}

unsigned int Table::getSize(){
    return size;
}

unsigned int Table::search(const Pair<string>& p){
    unsigned int c = 0;
    for (unsigned int i = 0;i<size;i++){
        if (a[i].first == p.first && a[i].second == p.second){
            c++;
        }
    }
    return c;
}