
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 170741SEP24
# Filename: implementation.cpp
# Dependency: arrayListImplementation.h
################################################*/
​
#include <iostream>
#include "ArrayListImplementation.h"
​
using namespace std;
​
int main()
{
	ArrayList<int> intList(10);
	int x;
	intList.print();
	cout << intList.isEmpty() << "\n";
	intList.insert(0); intList.insert(10); intList.insert(30);
	intList.print();
	cout << intList.isEmpty() << "\n";
	intList.insertAt(2, 20);
	intList.print();
	intList.insertEnd(40);
	intList.print();
	intList.insertAt(7, 20);
	intList.print();
	intList.insert(20);
	intList.clearList();
	intList.print();
	cout << intList.isFull() << "\n";
	cout << intList.isItemAtEqual(2, 20) << "\n";
	intList.remove(10);
	intList.print();
	intList.removeAt(3);
	intList.print();
	intList.replaceAt(2, 100);
	intList.print();
	cout << intList.seqSearch(30) << "\n";
	intList.retrieveAt(4, x);
	cout << x << "\n";
	ArrayList<int> newIntList(intList);
	cout << "New list contains: ";
	newIntList.print();
	ArrayList<int> list2(10);
	list2 = intList;
	cout << "List 2 contains: ";
	list2.print();
​
	/*ArrayList<char> charList(10);
	char x;
	charList.print();
	cout << charList.isEmpty() << "\n";
	charList.insert('A'); charList.insert('B'); charList.insert('D');
	charList.print();
	cout << charList.isEmpty() << "\n";
	charList.insertAt(2, 'C');
	charList.print();
	charList.insertEnd('E');
	charList.print();
	charList.insertAt(7, 'Z');
	charList.print();
	charList.insert('B');
	//charList.clearList();
	//charList.print();
	cout << charList.isFull() << "\n";
	cout << charList.isItemAtEqual(2, 'C') << "\n";
	charList.remove('B');
	charList.print();
	charList.removeAt(0);
	charList.print();
	charList.replaceAt(1, 'O');
	charList.print();
	cout << charList.seqSearch('Z') << "\n";
	charList.retrieveAt(0, x);
	cout << x << "\n";
	ArrayList<char> newCharList(charList);
	cout << "New list contains: ";
	newCharList.print();
	ArrayList<char> list2(10);
	list2 = newCharList;
	cout << "List 2 contains: ";
	list2.print();*/
​
	return 0;
}
