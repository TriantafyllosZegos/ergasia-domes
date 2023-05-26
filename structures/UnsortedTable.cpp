#include "UnsortedTable.h"
#include "../helpers/Pair.h"
#include <iostream>
#include <string>
using namespace std;

UnsortedTable::UnsortedTable(){
    a = new Pair<string>[1200];
    z = 0;
    
}

void UnsortedTable::insert(const Pair<string>& p){
    a[z] = p;
    z++;

}
void UnsortedTable::print(){
    for (int i = 2; i < z;i++){
        cout << a[i] << endl;
    }

}

Pair<string>* UnsortedTable::get(){
    return a;

}