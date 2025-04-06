
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 081253DEC24
# Filename: binaryTreeImplementation.h
# Dependency: binaryTree.h
################################################*/
​
#include "binaryTree.h"
​
template<class Type>
BinaryTree<Type>::BinaryTree(){                //constructor
  root = NULL;
}
​
template<class Type>
bool BinaryTree<Type>::isEmpty(){
  return(root == NULL);
}
​
template<class Type>
void BinaryTree<Type>::inorderTraversal(){     //this is a public function and calls the private function
  inorder(root);
}
​
template<class Type>
void BinaryTree<Type>::inorder(Node<Type>* p){
  if (p != NULL){
    inorder(p->lLink);
    cout << p->info << " ";
    inorder(p->rLink);
  }
}
​
template<class Type>
void BinaryTree<Type>::preorderTraversal(Node<Type>* p){
  preorder(root);
}
​
template<class Type>
void BinaryTree<Type>::preorder(Node<Type>* p){
  if (p != NULL){
    cout << p->info << " ";     //root
    preorder(p->lLink);         //left subtree
    preorder(p->rLink);         //right subtree
  }
}
​
template<class Type>
void BinaryTree<Type>::postorderTraversal(Node<Type>* p){
  postorder(root);
}
​
template<class Type>
void BinaryTree<Type>::postorder(Node<Type>* p){
  if (p != NULL){
    postorder(p->lLink);             //left subtree
    postorder(p->rLink);             //right subtree
    cout << p->info << " ";          //root
  }
}
​
template<class Type>
int BinaryTree<Type>::treeHeight(){
  return height(root);
}
​
template<class Type>
int BinaryTree<Type>::height(Node<Type>* p){
  if (p == NULL)
    return 0;
  else
    //1 is the root node + the no of nodes in the left subtree + the no of nodes in the right subtree
    return 1 + max(height(p->lLink), height(p->rLink));
}
​
template<class Type>
Type BinaryTree<Type>::max(Type x, Type y){
  if (x >= y)
    return x;
  else
    return y;
}
​
template<class Type>
int BinaryTree<Type>::treeNodeCount(){
  return nodeCount(root);
}
​
​
template<class Type>
int BinaryTree<Type>::nodeCount(Node<Type>* p){
  if (p == NULL)
    return 0;
  else
    //1 is the root node + the no of nodes in the left subtree + the no of nodes in the right subtree
    return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}
​
template<class Type>
int BinaryTree<Type>::treeLeavesCount(){
  return leavesCount(root);
}
​
/*leavesCount
Basic step:
  If the tree is empty, return 0
  If the tree contains only one node, return 1
Recursive step:
  Return the number of leaves of the left subtree + the number of leaves of the right subtree.
*/
template<class Type>
int BinaryTree<Type>::leavesCount(Node<Type>* p){
  if (p == NULL)
    return 0;
  if (p->lLink == NULL && p->rLink == NULL)
    return 1;
  else
    return leavesCount(p->lLink) + leavesCount(p->rLink);
}
​
template<class Type>
void BinaryTree<Type>::destroyTree()
{
  destroy(root);
}
​
template<class Type>
void BinaryTree<Type>::destroy(Node<Type>*& p){
  if (p != NULL){
    destroy(p->lLink);
    destroy(p->rLink);
    delete p;
    p = NULL;
  }
}
​
template<class Type>
BinaryTree<Type>::~BinaryTree(){
  destroy(root);
}
​
template<class Type>
bool BinarySearchTree<Type>::search(const Type& x){
  Node<Type>* current;
  bool found = false;
  if (this->root == NULL)
    cout << "Empty tree!" << endl;
  else{
    current = this->root;
    while (current != NULL && !found){
      if (current->info == x)
        found = true;
      else if (current->info > x)
	current = current->lLink;
      else
	current = current->rLink;
    }
  }
  return found;
}
​
template<class Type>
void BinarySearchTree<Type>::insert(const Type& x){
  Node<Type>* current, *prevCurrent=NULL, *newNode;
  newNode = new Node<Type>;
  assert(newNode != NULL);
  newNode->info = x;  newNode->lLink = NULL; newNode->rLink = NULL;
  if (this->root == NULL)
    this->root = newNode;
  else{
    current = this->root;
    while (current != NULL){
      prevCurrent = current;
      if (current->info == x){
        cout << "Item is already in the list!" << endl;
	return;
      }
      else if (current->info > x)
        current = current->lLink;
      else
        current = current->rLink;
    }
    if (prevCurrent->info > x)
      prevCurrent->lLink = newNode;
    else
      prevCurrent->rLink = newNode;
  }
}
​
template<class Type>
void BinarySearchTree<Type>::deleteFromTree(Node<Type>*& p){
  Node<Type>* current, *prevCurrent, *temp;
  if (p == NULL)
    cout << "The node to be deleted is NULL!" << endl;
  else if (p->llink == NULL && p->rlink == NULL) {//p points to a leaf
    temp = p;
    p = NULL;
    delete temp;
  }
  else if (p->llink == NULL) { //p points to a node with only a right child  
    temp = p;
    p = temp->rlink;
    delete temp;
  }
  else if (p->rlink == NULL) { //p points to a node with only a left child 
    temp = p;
    p = temp->llink;
    delete temp;
  }
  else { //p points to a node with two children
    current = p->llink;
    prevCurrent = NULL;
    while (current->rlink != NULL){
      prevCurrent = current;
      current = current->rlink;
    }
    p->info = current->info;
    if (prevCurrent == NULL)   //current did not move, current = p->llink, adjust p
    p->llink = current->llink;
    else
      prevCurrent->rlink = current->llink;
      delete current;
  }
}
​
//**************************   deleteNode   **************************
template<class Type>
void BinarySearchTree<Type>::deleteNode(const Type& x){
  Node<Type>* current;
  Node<Type>* prevCurrent;
  bool found = false;
  if (this->root == NULL)
    cout << "Cannot delete from an empty tree!" << endl;
  else{
    current = this->root;
    prevCurrent = this->root;
    while (current != NULL && !found){
      if (current->info == x)
        found = true;
      else{
        prevCurrent = current;
	if (current->info > x)
	  current = current->llink;
	else
	  current = current->rlink;
      }
    }
    if (current == NULL)
      cout << "The item is not in the tree!" << endl;
    else if (found){
      if (current == this->root)
        deleteFromTree(this->root);
      else
        if (prevCurrent->info > x)
	  deleteFromTree(prevCurrent->llink);
	else
	  deleteFromTree(prevCurrent->rlink);
    }
  }
}
