#ifndef CPAIR_H
#define CPAIR_H

#include <iostream>
using namespace std;

template<typename T> 
struct CPair : public Pair<T> {
    T first;
    T second;
    int count;
    CPair(T first,T second): first(first), second(second), count(1){};
    CPair(T first,T second,int c): first(first), second(second), count(c){};
    CPair(){}
    friend std::ostream& operator<<(std::ostream& os,CPair& pair) {
        return os << pair.first << "," << pair.second << " || count : " << pair.count;
    }
    
};

#endif 