
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 240957NOV24
# Filename: queueImplementation.h
# Dependency: queue.h
################################################*/
​
#include <assert.h>
#include "queue.h"
​
Queue<Type>::Queue(int maxSize){
  selfLength = 0;
  selfMaxSize = maxSize;
  selfFirst = NULL;
  selfLast = NULL;
}
​
template<class Type>
bool Queue<Type>::isEmpty(){
  return selfLength == 0;
}
​
template<class Type>
bool Queue<Type>::isFull(){
  return selfLength == selfMaxSize;
}
​
template<class Type>
int Queue<Type>::queueSize(){
  return selfLength;
}
​
template<class Type>
const void Queue<Type>::print(){
  if(isEmpty())
    cout << "The queue is empty, nothing to print\n";
  else{
    Node<Type>* current = selfFirst;
    while(current != NULL){
      cout << current->info << "";
      current = current->next;
    }
    cout << "\n";
  }
}
​
template<class Type>
Type Queue<Type>::front(){
  asset(selfFirst != NULL);
  return selfFirst->info;
}
​
template<class Type>
Type Queue<Type>::back(){
  assert(selfFirst != NULL);
  return selfLast->info;
}
​
template<class Type>
void Queue<Type>::enqueue(const Type& x){
  if(isFull())
    cout << "Can't insert in a full queue." << endl;
  else{
    Node<Type>* newNode;
    newNode = new Node<Type>;
    assert(newNode != NULL);
    newNode->info = x;
    newNode->next = NULL;
    
    if(selfFirst == NULL){
      selfFirst = newNode;
      selfLast = newNode;
    }
    else{
      selfLast->next = newNode;
      selfLast = newNode;
    }
    selfLength++;
  }
}
​
template<class Type>
void Queue<Type>::dequeue(){
  if(isEmpty())
    cout << "Empty queue. No node to delete\n";
  else{
    Node<Type>* current = selfFirst;
    if(selfFirst == selfLast){     //one one node in the queue
      delete current;
      selfFirst = selfLast = NULL;
    }
    else{     //more than one node in the queue
      selfFirst = selftFirst->next;
      delete current;
    }
    selfLength--;
  }
}
​
template<class Type>
Queue<Type>::Queue(const Queue<Type>& otherQueue){
  Node<Type>* current;               //pointer to traverse otherQueue
  if(selfFirst != NULL)
    destroyQueue();
  
  selfMaxSize = otherQueue.selfMaxSize;
  current = otherQueue.selfFirst;    //current points to the 1st node of otherQueue
  
  while(current != NULL){
    enqueue(current->info);
    current = current->next;
  }
}
​
template<class Type>
void Queue<Type>::destroyQueue(){
  Node<Type>* current
  
  while(selfFirst != NULL){
    current = selfFirst;
    selfFirst = selfFirst->next;
    delete current;
  }
  selfLast = NULL;
  selfLength = 0;
}
​
template<class Type>
Queue<Type>::~Queue(){
  cout << "The queue was destroyed\n";
  destroyQueue();
}
