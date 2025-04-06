/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 240957NOV24
# Filename: priorityQueue.h
# Dependency: N/A
################################################*/

template<class Type>
struct Node
{
  Type info;
  int selfPriority;
  Node<Type>* next;
};

template<class Type>
class PriorityQueue{
  int selfLength, selfMaxSize;
  Node<Type>* selfFirst;
  Node<Type>* selfLast;
  
  public:
    PriorityQueue(int);
    bool isEmpty();
    bool isFull();
    int queueSize();
    const void print();                         //modified
    void front(Type&, int&);                    //modified
    void back(Type&, int&);                     //modified
    void enqueue(const Type&, const int&);      //modified
    void dequeue();
    void destroyQueue();
    PriorityQueue(const PriorityQueue<Type>&);  //modified
    ~PriorityQueue();
};
