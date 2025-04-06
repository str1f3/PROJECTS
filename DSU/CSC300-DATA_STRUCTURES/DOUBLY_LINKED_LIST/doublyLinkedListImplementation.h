
#include <assert.h>
#include "doublyLinkedList.h"
​
template<class Type>
DoublyLinkedList(){             //constructor
  selfLength = 0;               //represents the number of nodes
  selfFirst = NULL;             //points to the first node
  selfLast = NULL;              //points to the last node
}
​
template<class Type>
bool DoublyLinkedList<Type>::isEmpty(){
  return selfLength == 0;
  //return selfFirst == NULL; or return selfLast == NULL;
}
​
template<class Type>
int DoublyLinkedList<Type>::listSize(){
  return selfLength;
}
​
template<class Type>
const void DoublyLinkedList<Type>::print(){
  if (isEmpty())
    cout << "The list is empty, nothing to print\n";
  else{
    Node<Type> *current = selfFirst;
    while (current != NULL){
      cout << current->info << " ";
      current = current->next;
    }
    cout << "\n";
  }
}
​
template<class Type>
const void DoublyLinkedList<Type>::printReverse(){
  if (isEmpty())
    cout << "The list is empty, nothing to print\n";
  else{
    Node<Type> *current = selfLast;
    while (current != NULL){
      cout << current->info << " ";
      current = current->prev;
    }
    cout << "\n";
  }
}
​
template<class Type>
Type DoublyLinkedList<Type>::front(){
  assert(selfFirst != NULL);
  return selfFirst->info;
}
​
template<class Type>
Type DoublyLinkedList<Type>::back(){
  assert(selfFirst != NULL);
  return selfLast->info;
}
​
template<class Type>
void DoublyLinkedList<Type>::insertFirst(const Type& varX){
  Node<Type> *newNode;
  newNode = new Node<Type>;
  assert(newNode != NULL);
  newNode->info = varX;
  newNode->prev = NULL;
  if (selfFirst == NULL){       //empty list
    selfFirst = newNode;
    selfLast = newNode;
    newNode->next = NULL;
  }
  else{
    newNode->next = selfFirst;
    selfFirst->prev = newNode;
    selfFirst = newNode;
  }
  selfLength++;
}
​
template<class Type>
void DoublyLinkedList<Type>::insertLast(const Type& varX){
  Node<Type> *newNode;
  newNode = new Node<Type>;
  assert(newNode != NULL);
  newNode->info = varX;
  newNode-> = NULL;
  if (selfLast == NULL){  //empty list
    selfFirst = newNode;
    selfLast = newNode;
    newNode->prev = NULL;
  }
  else{
    newNode->prev = selfLast;
    selfLast->next = newNode;
    selfLast = newNode;
  }
  selfLength++;
}
​
template<class Type>
bool DoublyLinkedList<Type>::search(const Type& varX){
  Node<Type> *current;
  current = selfFirst;
  while (current != NULL)
    if (current->info == varX)
      return true;
    else
      current = current->next;
  return false;
}
    
template<class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& varX){
  if (isEmpty())
    cout << "Empty list. No node to be deleted\n";
  else{
    Node<Type> *current, *prevCurrent;
    current = selfFirst;
    prevCurrent = NULL;
    while (current != NULL && current->info != varX){
      prevCurrent = current;
      current = current->next;
    }
    if (current == NULL)
      cout << varX << " was not found in the linked list\n";
    else{ //the linked list is not empty & x was found.
      //linked list with only one node with info = varX
      if (selfFirst == selfLast){  
        delete current;
        selfFirst = NULL;
        selfLast = NULL;
      }
      //a list w/ more than one node & the first node has info = varX
      else if (current == selfFirst){
        selfFirst = selfFirst->next;
        selfFirst->prev = NULL;
        delete current;
      }
      //a list w/ more than one node & only the last node has info = varX
      else if (current == selfLast){
        selfLast = prevCurrent;
        selfLast->next = NULL;
        delete current;
      }
      //The node to be deleted is after first & before last
      else{
        prevCurrent->next = current->next;
        current-next->prev = prevCurrent;
        delete current;
      }
      selfLength++;
    }
  }
}
​
//this is the copy constructor
template<class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type>& otherList){
  Node<Type> *current;   //pointer to traverse the otherList
  if (selfFirst != NULL)
    destroyList();
  current = otherList.selfFirst;  //current points to the first node of otherList
  while (current != NULL){
    insertLast(current->info);
    current = current->next;
  }
  selfLength = otherList.selfLength;
}
​
//removes all the nodes in the DoublyLinkedList
template<class Type>
void DoublyLinkedList<Type>::destroyList(){
  Node<Type> *current;
  while (selfFirst != NULL){
    current = selfFirst;
    selfFirst = selfFirst->next;
    delete current;
  }
  selfLast = NULL;
  selfLength = 0;
}
​
template<class Type>
DoublyLinkedList<Type>::~DoublyLinkedList(){
  cout << "The list was destroyed\n";
  destroyList();
}
