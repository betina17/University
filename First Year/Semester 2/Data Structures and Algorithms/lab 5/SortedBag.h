#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

#include <utility>

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef std::pair<TComp, int> TPair; // value + frequency
typedef bool(*Relation)(TComp, TComp); 
#define NULL_TCOMP -11111;

class SortedBagIterator;

struct BSTNode
{
	TPair info;
	BSTNode* left;
	BSTNode* right;
};

class SortedBag {
	friend class SortedBagIterator;

private:
	BSTNode* root;
	int length; //length=nr of nodes*their frequency
	Relation r; //functie care compara valorile a doua noduri
	int removed;
	
	
	// initializes a new node for the tree
	BSTNode* initNode(TElem e) const;

	bool delete_rec(BSTNode* node, BSTNode* parent, TComp elem);

	BSTNode* maximum(BSTNode* node);
	

public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appears in the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();

	TComp leastFrequent() const;
};