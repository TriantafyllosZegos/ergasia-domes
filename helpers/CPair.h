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
    CPair(Pair<T>& p): first(p.first), second(p.second), count(1){};
    CPair(){}
    friend std::ostream& operator<<(std::ostream& os,CPair& pair) {
        return os << pair.first << "," << pair.second << " || count : " << pair.count;
    }
    friend bool operator==(const CPair& p1,const CPair& p2){
        return (p1.first == p2.first && p1.second == p2.second);
    }
    friend bool operator!=(const CPair& p1,const CPair& p2){
        return (p1.first != p2.first || p1.second != p2.second);
    }
    friend bool operator>(const CPair& p1,const CPair& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second));
    }
    friend bool operator<(const CPair& p1,const CPair& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
    }
    friend bool operator<=(const CPair& p1,const CPair& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second < p2.second));
    }
    friend bool operator>=(const CPair& p1,const CPair& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second > p2.second));
    }
    friend bool operator==(CPair p1,const Pair<T>& p2){
        return (p1.first == p2.first && p1.second == p2.second);
    }
    friend bool operator<=(CPair p1,const Pair<T>& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second < p2.second));
    }
    friend bool operator>=(CPair p1,const Pair<T>& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second == p2.second) || (p1.first == p2.first && p1.second > p2.second));
    }
    friend bool operator>(CPair p1,const Pair<T>& p2){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second));
    }
    friend bool operator<(CPair p1,const Pair<T>& p2){
        return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
    }
    explicit CPair(const Pair<string>& p) : first(p.first),second(p.second),count(1) {}  
    
};

#endif 