
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 240957NOV24
# Filename: priorityQueueImplementation.h
# Dependency: priorityQueue.h
################################################*/
​
#include <assert.h>
#include "priorityQueue.h"
​
template<class Type>
const void PriorityQueue<Type>::print(){
  if(selfFirst == NULL)
    cout << "The queue is empty, nothing to print\n";
  else{
    Node<Type>* current = selfFirst;
    while(current != NULL){
      cout << current->info << ", " << current->selfPriority << endl;
      current = current->next;
    }
  }
}
​
template<class Type>
void PriorityQueue<Type>::front(Type& x, int& p){
  assert(selfFirst != NULL);
  x = selfFirst->info;
  p = selfFirst->selfPriority;     //do we really need p?
}
​
template<class Type>
void PriorityQueue<Type>::back(Type& x, int& p){
  assert(selfFirst != NULL);
  x = selfLast->info;
  p = selfLast->selfPriority;     //do we really need p?
}
​
template<class Type>
void PriorityQueue<Type>::enqueue(const Type& x, const int& p){
  if (isFull())
    cout << "Can't insert in a full queue." << endl;
  else{
    Node<Type> *newNode, *current, *prevCurrent;
    newNode = new Node<Type>;
    assert(newNode != NULL);
    newNode->info = x;
    newNode->selfPriority = p;
    newNode->next = NULL;
      
      if (selfFirst == NULL)                //empty queue
        selfFirst = selfLast = newNode;
      else{
        prevCurrent = NULL;
	current = selfFirst;
	
	while (current != NULL && current->selfPriority >= p){
	  prevCurrent = current;
	  current = current->next;
	}
	if (current == selfFirst){         //The node has the highest priority and will be inserted at the beginning
	  newNode->next = selfFirst;
	  selfFirst = newNode;
	}
	else if (current == NULL){    //The node has the least priority and will be inserted at the end
	  selfLast->next = newNode;
	  slefLast = newNode;
	}
	else{
	  newNode->next = prevCurrent->next;
	  prevCurrent->next = newNode;
        }
      }
      selfLength++;
  }
}
​
template<class Type>
PriorityQueue<Type>::PriorityQueue(const PriorityQueue<Type>& otherQueue){
  Node<Type>* current;               //pointer to traverse otherQueue
  if (selfFirst != NULL)
    destroyQueue();
    selfMaxSize = otherQueue.selfMaxSize;
    current = otherQueue.selfFirst;     //current points to the first node of otherQueue 
	
  while (current != NULL){
    enqueue(current->info, current->selfPriority);
    current = current->next;
  }
}
