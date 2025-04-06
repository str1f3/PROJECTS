
#/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 170741SEP24
# Filename: arrayListImplementation.h
# Dependency: arrayListDesign.h
################################################*/
​
#include "ArrayListDesign.h"
#include <assert.h>
​
using namespace std;
​
template <class Type>
//constructor
ArrayList<Type>::ArrayList(int size) {
	selfLength = 0;
	if (size < 0) {
        cout << "The array size must be positive. Creating a default array of size 100.\n";
        selfMaxSize = 100;
    }
    else
        selfMaxSize = size;
    selfList = new Type[selfMaxSize];
    assert(selfList != NULL);             //capture programming error
}
​
template <class Type>
bool ArrayList<Type>::isEmpty() {
    return selfLength == 0;
    /*ALT procedure
    ** if (selfLength == 0)
    *    return true;
    *  else
    *    return false;
    */
}
​
template <class Type>
bool ArrayList<Type>::isFull() {
    return selfLength == selfMaxSize;
}
​
template <class Type>
int ArrayList<Type>::listSize() {
    return selfLength;
}
​
template <class Type>
int ArrayList<Type>::maxListSize(){
    return selfMaxSize;
}
​
template <class Type>
const void ArrayList<Type>::print() {
    if (isEmpty())
        cout << "Empty list\n";
    else {
        for (int i = 0; i < selfLength; i++)
            cout << selfList[i] << " ";
        cout << "\n";
    }
}
​
template <class Type>
bool ArrayList<Type>::isItemAtEqual(int position, const Type& x) {
    if (position < 0 || position >= selfMaxSize) {
        cout << "Valid positions must be in " << 0 << "..." << selfLength - 1 << "\n";
        return false;
    }
    else if (selfList[position] == x)
        return true;
    else
        return false;
}
​
template <class Type>
void ArrayList<Type>::insertAt(int position, const Type& x) {
    if (isFull())
        cout << "Can't insert in a full list.\n";
    else if (position < 0 || position > selfLength)
        cout << "Valid positions for insertion are " << 0 << "..." << selfLength << "\n";
    else {
        for (int i = selfLength; i > position; i--)
            selfList[i] = selfList[i - 1];
        selfList[position] = x;
        selfLength++;
    }
}
​
template <class Type>
void ArrayList<Type>::insertEnd(const Type& x) {
    if (isFull())
        cout << "Can't insert in a full list.\n";
    else {
        selfList[selfLength] = x;
        selfLength++;
    }
}
​
template <class Type>
void ArrayList<Type>::removeAt(int position) {
    if (isEmpty())
        cout << "Can't remove from an empty list.\n";
    else if (position < 0 || position >= selfLength)
        cout << "Valid positions for removal are " << 0 << "..." << selfLength - 1 << "\n";
    else {
        for (int i = position; i < selfLength - 1; i++)
            selfList[i] = selfList[i + 1];
        selfLength--;
    }
}
​
template <class Type>
void ArrayList<Type>::retrieveAt(int position, Type& x) {
    if (isEmpty())
        cout << "Can't retrieve from an empty list.\n";
    else if (position < 0 || position >= selfLength)
        cout << "Valid positions for retrieving are " << 0 << "..." << selfLength - 1 << "\n";
    else
        x = selfList[position];
}
​
template <class Type>
void ArrayList<Type>::replaceAt(int position, const Type& x) {
    if (isEmpty())
        cout << "Empty list.\n";
    else if (position < 0 || position >= selfLength)
        cout << "Valid positions for replacement are " << 0 << "..." << selfLength - 1 << "\n";
    else
        selfList[position] = x;
}
​
template <class Type>
void ArrayList<Type>::clearList() {
    selfLength = 0;
}
​
template <class Type>
int ArrayList<Type>::seqSearch(const Type& x) {
    if (isEmpty()) {
        cout << "Can't search in an empty list.\n";
        return -1;
    }
    else {
        for (int i = 0; i < selfLength; i++)
            if (selfList[i] == x)
                return i;
        return -1;
    }
}
​
template <class Type>
//without duplication
void ArrayList<Type>::insert(const Type& x) {
    if (selfLength == selfMaxSize)               //or if(isFull())
        cout << "Can't insert in a full list.\n";
    else if (selfLength == 0)                    //or if(isEmpty())
        selfList[selfLength++] = x;
    else {
        if (seqSearch(x) != -1)
            cout << "Duplication is not allowed\n";
        else
            selfList[selfLength++] = x;
    }
}
​
template <class Type>
void ArrayList<Type>::remove(const Type& x) {
    if (selfLength == 0)                         //or if (isEmpty())
        cout << "Can't remove from empty list\n";
    else {
        int i = seqSearch(x);
        if (i == -1)
            cout << x << " doesn't exist in the list\n";
        else
            removeAt(i);
    }
}
​
template <class Type>
//copy constructor
ArrayList<Type>::ArrayList(const ArrayList<Type>& otherList) {
    selfMaxSize = otherList.selfMaxSize;
    selfLength = otherList.selfLength;
    selfList = new Type[selfMaxSize];
    assert(selfList != NULL);                    //capture programming error
    for (int i = 0; i < selfLength; i++)
        selfList[i] = otherList.selfList[i];
}
​
template <class Type>
//destructor
ArrayList<Type>::~ArrayList() {
    delete[] selfList;
}
​
template <class Type>
const ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& otherList) {
    if (this != &otherList) {
        delete[] selfList;
        selfMaxSize = otherList.selfMaxSize;
        selfLength = otherList.selfLength;
        selfList = new Type[selfMaxSize];
        assert(selfList != NULL);
        for (int i = 0; i < selfLength; i++)
            selfList[i] = otherList.selfList[i];
    }
​
    return *this;
}
