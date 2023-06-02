#include "Table.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

Table::Table(){
    unsigned long long int z = 3900000;
    a = new(nothrow) Pair<string>[z]();
    if (a == NULL) cout << "TABLE MEMORY ERROR" << endl;
    size = 0;
    cap = 20000000;
    
}

/*
Table::~Table(){
    delete[] a;
    
}*/

void Table::insert(const Pair<string>& p){
    /*
    if (size == cap) {
        // If the array is full, increase its capacity
        cap += 20000000;
        Pair<string> * newLines = new(nothrow) Pair<string>[cap]();
        if (newLines == NULL) cout << "Table MEMORY ERROR || size : " << size << endl;

        // Copy the existing lines to the new array
        for (unsigned long long int i = 0; i < size; i++) {
                newLines[i] = a[i];
        }
        // Delete the old array
        delete[] a;
        // Update the lines pointer to point to the new array
        a = newLines;
    }*/
    // Store the new line
    a[size] = p;
    if (size % 1000000 == 0) cout << size << endl;
    size++;
}


void Table::print(){
    cout << "############## TABLE ##############" << endl;
    for (unsigned long long int i = 0; i < size;i++){
        cout << a[i] << endl;
    }
}

unsigned long long int Table::getSize(){
    return size;
}

int Table::search(const Pair<string>& p){
    unsigned int c = 0;
    for (int i = 0;i<size;i++){
        if (a[i].first == p.first && a[i].second == p.second){
            c++;
        }
    }
    return c;
}