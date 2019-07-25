#ifndef QUEUE_HEADER_HR
#define QUEUE_HEADER_HR
#include "Vector.h"
#include <iostream>
template <class T>
class Queue{
private:
  unsigned int front;
  unsigned int back;
  unsigned int qSize;
  Vector<T> * queue;
public:
  Queue(unsigned int size);
  ~Queue();
  bool enqueue(T data);
  T dequeue();
  T peek();
  bool empty();
  void clear();
};

template <class T>
Queue<T>::Queue(unsigned int size){
  queue = new Vector<T>(size);
  qSize = 0;
  front = 0;
  back = 1;
}
template <class T>
Queue<T>::~Queue(){
  delete queue;
  queue = NULL;
}
template <class T>
bool Queue<T>::enqueue(T data){
	back = back % queue->size();
	front = front % queue->size();
	if(empty()){
		(*queue)[front] = data;
		qSize++;
		return true;
	}
	if(back == front){//Queue is full
		return false;	
	}
	(*queue)[back] = data;
	back++;
	qSize++;
	return true;
}
template <class T>
T Queue<T>::dequeue(){
	front++;
	qSize--;
	return (*queue)[front-1];
}
template <class T>
T Queue<T>::peek(){
	return (*queue)[front];
}
template <class T>
bool Queue<T>::empty(){
	if(qSize <= 0){return true;}
	return false;
}
template <class T>
void Queue<T>::clear(){
	qSize = 0;
	front = 0;
	back = 1;
}




#endif
