#include "Table.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

Table::Table(){
    
    a = new(nothrow) Pair<string>[100000]();
    if (a == NULL) cout << "TABLE MEMORY ERROR" << endl;
    size = 0;
    cap = 100000;
    
}

/*
Table::~Table(){
    delete[] a;
    
}*/


void Table::insert(Pair<string>& p){
    if (size == cap) {
        // If the array is full, increase its capacity
        cap += 100000;
        Pair<string> * newLines = new(nothrow) Pair<string>[cap]();
        if (newLines == NULL) cout << "Table MEMORY ERROR || size : " << size << endl;

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
    if (size % 100000 == 0) cout << size << endl;
    size++;
    

}


void Table::print(){
    cout << "############## TABLE ##############" << endl;
    for (int i = 0; i < size;i++){
        cout << a[i] << endl;
    }

}

int Table::getSize(){
    return size;
}
void Table::search(Pair<string>* arr){
    cout << "Search!!!" << endl;
}