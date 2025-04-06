#include <assert.h>

template <class Type>
struct Node
{
  Type info;
  Node<Type> *next;
};

template <class Type>
class LinkedList
{
  protected:
    //selfLength stores the number of nodes in the Linked List
    int selfLength;
    //selfFirst points to the first node in the Linked List
    Node<Type>* selfFirst;  // "cout << selfFirst" will print the memory location where selfFirst is stored
                            // "cout << first->info" will print the actual data value
                            // the "->" symbol is used to access the fields of each node!  
    //selfLast points to the last node in the Linked List
    Node<Type>* selfLast;
  public:
    LinkedList();           //constructor
    bool isEmpty();         //checks whether the linked list is empty
    int listSize();         //returns the number of nodes
    const void print();     //displays the information inside the nodes
    Type front();           //returns the information of the first node
    Type back();            //returns the information of the last node
    void insertFirst(const Type&);   //insert a node at the beginning of the linked list
    void insertLast(const Type&);    //insert a node at the end of the linked list
    bool search(const Type&);        //searches for elements in the linked list
    void deleteNode(const Type&);    //searches for the specified element/node and deletes it from the linked list
    LinkedList(const LinkedList<Type>&); //copy constructor; copies the list
    void destroyList();
    ~LinkedList();                       //destructor - deletes and deallocates the memory occupied by the linked list
};

//CONSTRUCTOR
template<class Type>
LinkedList<Type>::LinkedList(){
  // will store the number of nodes in the Linked List
  selfLength = 0;
  // will point to the first node in the Linked List
  selfFirst = NULL;
  // will point to the last node in the Linked List
  selfLast = NULL;
}

//ISEMPTY()
//returns true if the list is empty or false otherwise
template <class Type>
bool LinkedList<Type>::isEmpty(){
  return selfLength == 0;
  //return first == NULL; or return last == NULL
}

//LISTSIZE()
//returns the number of nodes stored in the list
template <class Type>
int LinkedList<Type>::listSize(){
  return selfLength;
}

//prints the different nodes of the linked list
template <class Type>
const void LinkedList<Type>::print(){
  if (isEmpty())
    cout << "The list is empty, nothing to print.\n";
  else{
    //see TRAVERSING LINKED LIST in the Definitions section
    //
    Node<Type>* current = selfFirst;
    while (current != NULL){
      cout << current->info << " ";
      current = current->next;
    }
    cout << "\n";
  }
}

//returns the information of the first node
//FRONT()
template <class Type>
Type LinkedList<Type>::front(){
  //the assert function is used to check whether the list is empty or not
  //if assert() determines that the list is empty it will stop program execution
  //if assert() determines that the list is NOT empty, it will return information on the first node
  assert(selfFirst != NULL);
  return selfFirst->info
}

//returns the information of the last node
//BACK()
Type LinkedList<Type>::back(){
  //the assert function is used to check whether the list is empty or not
  //if assert() determines that the list is empty it will stop program execution
  //if assert() determines that the list is NOT empty, it will return information on the first node
  assert(selfFirst != NULL);
  return selfLast->info;
}

/*The member function insertFirst inserts the new item at the beginning of the list.
 *The Algorithm is:
 * 01.Create a new node
    - this is done through the example below
       Node<Type>* temp;
       temp = new Node<Type>; //this line is used to create the node
       temp->info = x;
       temp->next = NULL;
 * 02.If unable to create the node, terminate the program
    - this simply calls the assert() function 
 * 03.Store the new item in the new node
 * 04.Insert the node before first
 * 05.Increment count by 1
 */
 
template <class Type>
void LinkedList<Type>::insertFirst(const Type& x){
  Node<Type>* newNode;           //pointer to the new node
  newNode = new Node<Type>;      //this line is used to create the node
  assert(newNode != NULL);       //checks whether the node was created
  newNode->info = x;             //insert the value of x to newNode->info (think of the -> as similar to the "
  newNode->next = selfFirst;     //newNode->next points to the first node
  selfFirst = newNode;           //assign the newly created node to selfFirst
  selfLength++;                  //increment the number of nodes in the Linked List
  if (selfLast == NULL)
    selfLast = newNode;
}

template <class Type>
void LinkedLinst<Type>::insertLast(const Type& x){
  //these five lines of code creates a new node
  Node<Type>* newNode;          //pointer to the new node
  newNode = new Node<Type>;     //this line is used to create the node
  assert(newNode != NULL);      //checks whether the node was created
  newNode->info = x;            //insert the value of x to newNode->info (think of the -> as similar to the "dot" access operator)
  newNode->next = NULL;     
  
  if (selfFirst == NULL)
    selfFirst = selfLast = newNode;
  else{
    selfLast->next = newNode;
    selfLast = newNode;
  }
  selfLength++;
}

/*The member function search() searches for a given item. If the item is found, it
  returns true, otherwise it returns false. The search must start from the first node.
   - compare the search item with the current node in the list. if the info of the
     current node is the same as the search item, stop the search; otherwise, make
     the next node the current node.
   - repeat step 1 until either the item is found or no more data is left in the
     list to compare with the search item.
 */
//SEARCH()
template <class Type>
bool LinkedList<Type>::search(const Type& x){
  Node<Type>* current;
  bool found;
  current = selfFirst;
  found = false;
  while (current != NULL && !found)
    if (current->info == x)               //this is one way to stop the loop
      found = true;
    else
      current = current->next;
  return found;
}

//deletes all nodes one after the other via loop until all nodes are deleted
//DESTROYLIST()
template <class Type>
void LinkedList<Type>::destroyList(){
  Node<Type>* current;
  while (selfFirst != NULL){
    current = selfFirst;
    selfFirst = selfFirst->next;
    delete currrent;
  }
  selfLast = NULL;
  selfLength = 0;
}

//DESTRUCTOR
template <class Type>
LinkeList<Type>::~LinkedList(){
  cout << "The list was destroyed\n";
  destroyList();
}

//makes a copy of a Linked List into another Linked List
//COPY CONSTRUCTOR
template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& otherList){
  Node<Type>* current;      //pointer to traverse the otherList
  if (selfFirst != NULL)
    destroyList();
  current = otherList.selfFirst;
  while (current != NULL){
    insertLast(current->info);
    current = current->next;
  }
  selfLength = otherList.selfLength;
}

/*if the list is empty
    print(can't delete from an empty list)
  else if the first node is the node w/ the given info,
    adjust first, last(if necessary), length, and deallocate the memory
  else
    search the list for the node w/ the given info
    if such a node is found, delete it & adjust the values of last (if necessary), and length
 */
//DELETENODE()
template<class Type>
void LinkedList<Type>::deleteNode(const Type& x)
{
  if (isEmpty())
    cout << "Empty linked list. No node to be deleted\n";
  else { // The linked list is not empty
    //this *prevCurrent is required IOT move through the search
    Node<Type>* current, *prevCurrent;
    current = selfFirst;
    prevCurrent = NULL;
    // this iterates through the Linked List until "x" is found
    // when "x" is found then use comparison starting w/ 1st if
    while (current != NULL && current->info != x) {
      prevCurrent = current;
      current = current->next;
    }
    // when "x" is found then use comparison starting w/ 1st if
    if (current == NULL)
      cout << x <<" was not found in the linked list\n"; 
    else { // the linked list is not empty and x was found.
      if { (selfFirst == selfLast)//Linked list with only one node with info = x
        delete current;
	selfFirst = NULL;
	selfLast = NULL;
      }
      else if (current == selfFirst) { //A list with more than one node and the first node has info = x
        selfFirst = selfFirst->next;
	delete current;
      }
      else if (current == selfLast) {//A list with more than one node and only the last node has info = x
        selfLast = prevCurrent;
	selfLast->next = NULL;
	delete current;
      }
      else {//The node to be deleted is after first and before last
        prevCurrent->next = current->next;
	delete current;
      }
      // this shortens the length of the Link List since one of the item was deleted
      selfLength--;
    }
  }
}
