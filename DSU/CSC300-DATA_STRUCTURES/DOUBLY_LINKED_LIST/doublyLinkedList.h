template<class Type>
struct Node
{
  Type info;
  Node<Type> *prev, *next;
};

class DoublyLinkedList
{
  int selfLength;
  Node<Type> *selfFirst;
  Node<Type> *selfLast;
  
  public:
    DoublyLinkedList();             //constructor
    
    bool isEmpty();
    int listSize();
    const void print();
    const void printReverse();
    Type front();
    Type back();
    void insertFirst(const Type&);
    void insertLast(const Type&);
    bool search(const Type&);
    void deleteNode(const Type&);
    DoublyLinkedList(const DoublyLinkedList<Type>&);
    void destroyList();
    ~DoublyLinkedList();
};
