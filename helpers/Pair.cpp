#include "Pair.h"
#include <iostream>

template<typename T>
Pair<T>::Pair(T first_value, T second_value){
  this->first = first_value;
  this->second = second_value;
  this->count = 1;
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
int Pair<T>::getCount(){
  return this->count;
}

template<typename T> 
void Pair<T>::setFirst(T first_value){
  this->first = first_value;
}

template<typename T> 
void Pair<T>::setSecond(T second_value){
  this->second = second_value;
}
template<typename T> 
void Pair<T>::increaseCount(int value){
  this->count = count + value;
}
    

template class Pair<std::string>;
