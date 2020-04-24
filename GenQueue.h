#include <iostream>
#include "NaiveList.h"

using namespace std;

template <typename T>
class GenQueue{
public:
  GenQueue();
  ~GenQueue();

  void insert(T d);
  T remove();
  T peek();
  bool isEmpty();
  int getSize();
  int size;

  NaiveList<T> myQueue;
};

template <typename T>
GenQueue<T>::GenQueue(){
  NaiveList<T> myQueue;
  size = 0;
}

template <typename T>
GenQueue<T>::~GenQueue(){
}

template <typename T>
void GenQueue<T>::insert(T d){
  myQueue.insertBack(d);
  size = myQueue.getSize();
}

template <typename T>
T GenQueue<T>::remove(){
  T c = myQueue.removeFront();
  size = myQueue.getSize();
  return c;
}

template <typename T>
T GenQueue<T>::peek(){
  return myQueue.getFront();
}

template <typename T>
bool GenQueue<T>::isEmpty(){
  return (size == 0);
}

template <typename T>
int GenQueue<T>::getSize(){
  return size;
}
