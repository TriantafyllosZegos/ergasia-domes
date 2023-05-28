
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template<typename T> class Pair {
  private:
    T first;
    T second;
    int count;
  public:
    Pair();
    Pair(T first,T second);

    void swap();

    T getFirst();
    T getSecond();
    int getCount();

    void setFirst(T first);
    void setSecond(T second);
    void increaseCount(int value);

    friend std::ostream& operator<<(std::ostream& os,Pair& pair) {
        return os << pair.getFirst() << "," << pair.getSecond() 
        << " || c : " << pair.getCount() ;
    }
    
};

#endif 