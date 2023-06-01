
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
    friend std::ostream& operator<<(std::ostream& os,const Pair& pair) {
        return os << pair.first << "," << pair.second ;
    }
    friend bool operator==(const Pair& p1,const Pair& p2){
        return (p1.first == p2.first && p1.second == p2.second);
    }
    friend bool operator!=(const Pair& p1,const Pair& p2){
        return (p1.first != p2.first || p1.second != p2.second);
    }
    friend bool operator>(const Pair& p1,const Pair& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second));
    }
    friend bool operator<(const Pair& p1,const Pair& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
    }
    friend bool operator<=(const Pair& p1,const Pair& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second < p2.second));
    }
    friend bool operator>=(const Pair& p1,const Pair& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second > p2.second));
    }
    
};

#endif 