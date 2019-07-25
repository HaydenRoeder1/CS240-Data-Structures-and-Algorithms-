/*
#include "Heap.h"
template <class T>
Heap<T>::Heap(){
  std::vector<T> v(0);
  list = v;
}
template <class T>
Heap<T>::Heap(std::vector<T> vect){
  this->list = vect;
  heapify();
}
template <class T>
void Heap<T>::addElement(T element){
  list.insert(list.begin(), element);
  siftdown(0);
}
template <class T>
T Heap<T>::getPriority(){
  if(!empty()){
    T value = list[0];
    list[0] = list[list.size() - 1];
    list[list.size() - 1] = value;
    list.pop_back();
    siftdown(0);
    return value;
  }else{
    T value;
    return value;
  }
}
template <class T>
bool Heap<T>::empty(){
  return list.empty();
}
template <class T>
void Heap<T>::heapify(){
  for(int i = (list.size() - 2)/2; i >= 0; i--){
    siftdown(i);
  }
}
template <class T>
void Heap<T>::siftdown(int i){
  while(!isLeaf(i)){
    int n = left(i);
    if(n+1 < list.size() && list[n] < list[n+1]){
      n=right(i);
    }
    if(list[i] > list[n]){return;}
    else{
      T temp = list[i];
      list[i] = list [n];
      list[n] = temp;
    }
    i = n;
  }

}
template <class T>
int Heap<T>::left(int index){
  return (2*index + 1 < list.size()) ? 2*index+1:-1;
}
template <class T>
int Heap<T>::right(int index){
  return (2*index + 2 < list.size()) ? 2*index + 2: -1;
}
template <class T>
bool Heap<T>::isLeaf(int index){
  int i = index;
  return (left(i) == -1 && right(i) == -1);
}
*/
