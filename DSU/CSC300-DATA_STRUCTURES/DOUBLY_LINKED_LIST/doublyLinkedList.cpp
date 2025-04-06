#include <iostream>
#include "doublyLinkedListImplementation.h"
using namespace std;

int main()
{
  DoublyLinkedList<float> list;
  list.insertLast(5.1);
  list.insertLast(10.2);
  list.insertLast(15.6);
  list.insertLast(12.3);
  list.insertLast(30.8);
  list.insertLast(35.1);
  list.insertLast(4.7);
  list.insertLast(50.9);
  list.insertLast(60.6);
  list.print();
  
  cout << "Is list sorted? " << list.isSortedList() << endl;
  
  list.reverseNodes();
  list.print();
  
  //palindrome is a word, sentence, verse, or numbers that reads the same backward or forward
  //examples noon, civic, racecar, level, and mom
  cout << "Is the list a palindrome? " << list.isPalindrome() << endl;
  cout << "Number of big nodes: " << list.bigNodes() << endl;

  /*
  LinkedList<int> list;        //create a list w/ default values as set by the constructor
  list.insertFirst(10);
  list.print();//10
  list.deleteNode(10);
  list.print();//Empty list
  list.insertFirst(10);
  list.insertFirst(20);
  list.insertFirst(30);
  list.insertFirst(40);
  list.print();//40 30 20 10
  list.deleteNode(40);
  list.print();//30 20 10
  LinkedList<int> list2(list);
  list2.print();
  cout << list2.search(20)<<"\n";
  */

  /*
  //cout << list.front() << "\n";//40
  cout << list.isEmpty() << "\n"; //0
  cout << list.listSize() << "\n";//4
  list.print();//40 30 20 10
  list.insertLast(-1);
  list.print();//40 30 20 10 -1
  cout << list.search(100) << "\n"; //0
  list.destroyList();
  */

  return 0;
}
