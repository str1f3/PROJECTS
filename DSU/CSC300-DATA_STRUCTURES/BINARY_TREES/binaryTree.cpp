#include<iostream>
using namespace std;
#include"BinarySearchTree.h"

void main()
{
	BinarySearchTree<int> bst;
	bst.insert(3);
	bst.insert(5);
	bst.insert(2);
	bst.insert(-1);
	bst.insert(4);
	bst.insert(6);
	bst.insert(-3);
	bst.insert(1);
	bst.insert(0);
	//bst.inorderTraversal();
	bst.postorderTraversal();
	bst.deleteNode(-3);
	cout << "\n";
	bst.postorderTraversal();
	//bst.preorderTraversal();
	cout << "\nNumber of leaves: "<<bst.treeLeavesCount() << endl;;
}
