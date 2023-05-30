
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template<typename T> 
struct Pair {
    T first;
    T second;
    Pair(T first,T second)
        : first(first), second(second){}
    Pair(){}
    friend std::ostream& operator<<(std::ostream& os,Pair& pair) {
        return os << pair.first << "," << pair.second ;
    }
    
};

#endif 