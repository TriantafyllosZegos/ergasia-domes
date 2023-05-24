#include "UnsortedTable.h"
#include <string>

using namespace std;

UnsortedTable::UnsortedTable(){
    ptr = NULL;
    int arr;
    
}

void UnsortedTable::add(pair<string,string> p){
    ptr = new pair(p);

}