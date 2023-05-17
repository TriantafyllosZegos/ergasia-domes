#ifndef AVL_H
#define AVL_H
#include <iostream>

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