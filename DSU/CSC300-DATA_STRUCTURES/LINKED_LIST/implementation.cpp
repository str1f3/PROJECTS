
#include<iostream>
using namespace std;
#include"LinkedList.h"
​
int main()
{
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
}
​
/*
//cout << list.front() << "\n";//40
cout << list.isEmpty() << "\n"; //0
cout << list.listSize() << "\n";//4
list.print();//40 30 20 10
list.insertLast(-1);
list.print();//40 30 20 10 -1
cout << list.search(100) << "\n"; //0
list.destroyList();*/
