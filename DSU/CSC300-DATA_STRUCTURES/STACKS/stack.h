
#include "arrayList.h"
​
template<class Type>
class Stack : public ArrayList<Type>
{
  public:
    Stack(int);
    bool isEmpty();
    bool isFullStack();
    void printStack();
    void push(const Type& x);
    Type top();
    void pop();
};
​
template<class Type>
Stack<Type>::Stack(int maxSize) : ArrayList<Type>(maxSize){
  //we call the constructor of the ArrayList with a parameter maxSize
  //the maxSize in ArrayList<Type>(maxSize) will be the maximum number
  //hence, there is no statement necessary in this section
}
​
template<class Type>
bool Stack<Type>::isEmpty(){
  return ArrayList<Type>::isEmpty();
}
​
template<class Type>
bool Stack<Type>::isFullStack(){
  return ArrayList<Type>::isFull();
}
​
template<class Type>
bool Stack<Type>::printStack();{
  ArrayList<Type>::print();
}
​
template<class Type>
void Stack<Type>::push(const Type& x){
  ArrayList<Type>::insertEnd(x);
}
​
template<class Type>
Type Stack<Type>::top(){
  int n;
  Type x;
  n = ArrayList<Type>::listSize();
  //the position at n-1 will be stored in x
  ArrayList<Type>::retrieveAt(n-1, x);
  return x;
}
​
template<class Type>
void Stack<Type>::pop(){
  int n;
  n = ArrayList<Type>::listSize();
  ArrayList<Type>::removeAt(n - 1);
}
