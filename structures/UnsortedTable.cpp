#include "UnsortedTable.h"
#include <iostream>
#include <string>

UnsortedTable::UnsortedTable(){
    pair<string,string> a[1000];
    int z = 0;
    
}

void UnsortedTable::add(pair<string,string> p){
    a[z] = p;
    z++;

}
void UnsortedTable::print(){
    for (int i = 0; i < 5;i++){
        cout << a[i].first << "," << a[i].second << endl;
    }

}
void UnsortedTable::printFirst(){
        cout << a[0].first << "," << a[0].second << endl;

}

pair<string,string>* UnsortedTable::get(){
    return a;

}