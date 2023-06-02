#include "HashTable.h"
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include "../helpers/Pair.h"

using namespace std;

//na koitaksoume to size !!!
Hashtable::Hashtable(int size){
    this->size = size;
    buckets.resize(size);
}


int Hashtable::hash(const Pair<string>& key){
    int num1 = 0;
    int num2 = 0;
    int i = 1;


    
    for (char ch : key.first) {
        num1 = num1 + static_cast<int>(ch)*i;
        i *= 10;
        
    }
    i = 1;
    for (char ch : key.second) {
        num2 = num2 + static_cast<int>(ch)*i;
        i *= 10;
        
    }

    return (num1 * num2 + num1) % size;



}


void Hashtable::insert(const Pair<string>& key){
    int index = hash(key);
    buckets[index].push_back(key);

}


int Hashtable::search(const Pair<string>& key){
    int index = hash(key);
    for (const auto& pair : buckets[index]){
        if (pair == key){
            return index;
        }
    }
    return -1;
}


void Hashtable::remove(const Pair<string>& key){
    int index = hash(key);
    for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
        if (*it == key) {
            buckets[index].erase(it);
            break;
        }
    }
}