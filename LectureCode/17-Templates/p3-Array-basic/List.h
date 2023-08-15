#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include "Book.h"

using namespace std;
template <class T>
class List
{
  template <class V>
  friend ostream& operator<<(ostream&, List<V>&);
  
  public:
    List();
    ~List();
    bool isEmpty();
    T& operator[](int);
    void add(const T&);
    T& remove(int);
    //void print() const;
    

  protected:
  class Node
    {
      public:
        T data;
        Node* next;
    };
    Node* head;

};


template <class T>
List<T>::List() : head(NULL){ }

//We have to change this so that it does not delete data
template <class T>
List<T>::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
bool List<T>::isEmpty(){
  return head == NULL;
}

template <class T>
T& List<T>::operator[](int index){
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  int currIndex = 0;

  while (currIndex < index && currNode!=NULL) {
      currNode = currNode->next;
      ++currIndex;
  }

  if (currNode == NULL){
    cerr<<"Invalid index"<<endl;
    exit(1);
  }else{
    return currNode->data;
  }
}

template <class T>

void List<T>::add(const T& loc)
{
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;
  newNode->data = loc;
  newNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL){
    head = newNode;
  }else{
    prevNode->next = newNode;
  }
  newNode->next = currNode;
}


template <class T>
T& List<T>::remove(int index)
{
 
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  int currIndex = 0;

  while (currIndex < index && currNode!=NULL) {
      prevNode = currNode;
      currNode = currNode->next;
      ++currIndex;
  }

  if (currNode == NULL){
    cerr<<"Invalid index"<<endl;
    exit(1);
  }
  
  T data = currNode->data;
  if (prevNode != NULL){
    prevNode->next = currNode->next;
  }else{
    head = currNode->next;
  }
  delete currNode;
  return data;
  

}


  
template <class T>
ostream& operator<<(ostream& out, List<T>& list)
{
  typename List <T>::Node* currNode = list.head;

  while (currNode != NULL) {
    out<<currNode->data<<endl<<endl;
    currNode = currNode->next;
  }
  return out;
}
#endif

