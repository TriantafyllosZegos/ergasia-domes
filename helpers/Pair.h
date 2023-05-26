
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template<typename T> class Pair {
  private:
    T first;
    T second;
  public:
    Pair();
    Pair(T first,T second);

    void swap();

    T getFirst();
    T getSecond();

    void setFirst(T first);
    void setSecond(T second);

    friend std::ostream& operator<<(std::ostream& os,Pair& pair) {
        return os << pair.getFirst() << "," << pair.getSecond();
    }
    
};

#endif 