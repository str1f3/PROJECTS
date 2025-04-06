/*################################################
# Name: Stephen Razon
# Student ID:
# Date: 111003NOV24
# Filename: arrayList.h
# Dependency: N/A
################################################*/

template <class Type>
class ArrayList
{
protected:
	int selfLength, selfMaxSize;
	Type* selfList;
public:
	ArrayList(int);              //constructor
	bool isEmpty();
	bool isFull();
	int listSize();
	int maxListSize();
	const void print();
	bool isItemAtEqual(int, const Type&);
	void insertAt(int, const Type&);
	void insertEnd(const Type&);
	void removeAt(int);
	void retrieveAt(int, Type&);
	void replaceAt(int, const Type&);
	void clearList();
	int seqSearch(const Type&);
	void insert(const Type&);    //without duplication
	void remove(const Type&);
	ArrayList(const ArrayList<Type>&);     //copy constructor
	~ArrayList();
	const ArrayList<Type>& operator=(const ArrayList<Type>&);
};
