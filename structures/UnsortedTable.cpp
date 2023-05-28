#include "UnsortedTable.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

UnsortedTable::UnsortedTable(){
    
    a = new(nothrow) Pair<string>[300004];
    if (a == NULL) cout << "UNSORTEDTABLE MEMORY ERROR" << endl;
    size = 0;
    
}
/*
UnsortedTable::~UnsortedTable(){
    delete[] a;
    
}*/


void UnsortedTable::insert(Pair<string>& p){
    for (int i=0;i<size;i++){
        if (a[i].getFirst() == p.getFirst() && a[i].getSecond() == p.getSecond() ){
            a[i].increaseCount(1);
            return;
        }
    }
    a[size] = p;
    size++;
    

}

void UnsortedTable::print(){
    cout << "############## UNSORTED TABLE ##############" << endl;
    for (int i = 0; i < size-1;i++){
        cout << a[i] << endl;
    }

}

int UnsortedTable::getSize(){
    return size;
}