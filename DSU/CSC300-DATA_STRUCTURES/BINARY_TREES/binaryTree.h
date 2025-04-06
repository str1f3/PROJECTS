
/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 081253DEC24
# Filename: binaryTree.h
# Dependency: N/A
################################################*/
​
template<class Type>
struct Node
{
  Type info;
  Node<Type>* lLink;
  Node<Type>* rLink;
};
​
template<class Type>
class BinaryTree
{
  protected:
    Node<Type>* root;
  
  //these functions are used to assist in the implementation of the public functions
  private:
    void destroy(Node<Type>*&);
    void inorder(Node<Type>*);
    void preorder(Node<Type>*);
    void postorder(Node<Type>*);
    int height(Node<Type>*);
    int max(int, int);
    int nodeCount(Node<Type>*);
    int leavesCount(Node<Type>*);
    
  //these functions doesn't have parameter to prevent the root from being manipulated
  public:
    BinaryTree(); 
    bool isEmpty();
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int treeHeight();
    int treeNodeCount();
    int treeLeavesCount();
    void destroyTree();
    ~BinaryTree();
};
​
//inheritance
template<class Type>
class BinarySearchTree : public
BinaryTree<Type>
{
  private:
    void deleteFromTree(Node<Type>*&);
  public:
    bool search(const Type&);
    void insert(const Type&);
    void deleteNode(const Type&);
};
