
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 240957NOV24
# Filename: queue.h
# Dependency: N/A
################################################*/
​
template<class Type>
struct Node
{
  Type info;
  Node<Type>* next;
};
​
class Queue{
  int selfLength, selfMaxSize;
  Node<Type>* selfFirst;
  Node<Type>* selfLast;
  
  public:
    Queue(int);                  //constructor
    bool isEmpty();
    bool isFull();
    int queueSize();             //returns the number of nodes in the queue
    const void print();          //print the elements of the queue
    Type front();                //returns the info of the 1st node
    Type back();                 //returns the info of the last node
    void enqueue(const Type&);   //add a new element at the end of the queue
    void dequeue();              //remove the element in the front of the queue
    void destroyQueue();         //remove all of the element
    Queue(const Queue<Type>&);   //copy constructor; makesa copy of the current queue 
    ~Queue();                    //destructor
};
