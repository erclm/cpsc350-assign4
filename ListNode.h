#include <iostream>

template <typename T>
class ListNode{
public:
  ListNode();
  ListNode(T d);
  ~ListNode();

  T data;
  ListNode *next;
  ListNode *prev;
};

template <typename T>
ListNode<T>::ListNode(){

}

template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; //null pointer
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}
