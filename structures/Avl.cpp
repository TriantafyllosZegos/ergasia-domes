#include "Avl.h"
#include <iostream>

template<typename T>
Pair<T>::Pair(T first_value, T second_value){
  this->first = first_value;
  this->second = second_value;
}

template<typename T>
Pair<T>::Pair(){
}

template<typename T> 
void Pair<T>::swap(){
  T temp = getFirst();
  setFirst(getSecond());
  setSecond(temp);
}

template<typename T> 
T Pair<T>::getFirst(){
  return this->first;
}
template<typename T> 
T Pair<T>::getSecond(){
  return this->second;
}

template<typename T> 
void Pair<T>::setFirst(T first_value){
  this->first = first_value;
}

template<typename T> 
void Pair<T>::setSecond(T second_value){
  this->second = second_value;
}
    

template class Pair<int>;
template class Pair<std::string>;
