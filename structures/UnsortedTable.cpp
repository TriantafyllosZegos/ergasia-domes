#include "UnsortedTable.h"
#include <string>

using namespace std;

UnsortedTable::UnsortedTable(){
    pair<string,string> a[10000];
    int z = 0;
    
}

void UnsortedTable::add(pair<string,string> p){
    a[z] = p;
    z++;

}
void UnsortedTable::print(){
    for (int i = 0; i < z;i++){
        cout << a[i].first << "," << a[i].second << std::endl;
    }

}