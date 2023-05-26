#include "UnsortedTable.h"
#include <iostream>
#include <string>

UnsortedTable::UnsortedTable(){
    Pair<string> a[1000];
    this->z = 0;
    
}

void UnsortedTable::add(Pair<string> p){
    a[this->z] = p;
    this->z++;

}
void UnsortedTable::print(){
    for (int i = 0; i < 5;i++){
        cout << a[0] << endl;
    }

}

Pair<string>* UnsortedTable::get(){
    return a;

}