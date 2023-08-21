#pragma once
#include <utility>
#include <vector>
//DO NOT INCLUDE MAPITERATOR

/*
 TODO: PROBLEM STATEMENT
 ADT Map–using a DLLA with (key, value) pairs
*/

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111)
#define NULL_TKEY -99999
class MapIterator;

/*typedef std::pair<TKey, TValue> TElem;
TElem elem = std::make_pair(1,2);
	//return the first element of the pair
	cout << elem.first << endl;
	cout << elem.second;  return the second element of the pair
	functiile astea implicite de first si second exista pt pairs, ca si pair si make_pair
*/


class Map {
	//DO NOT CHANGE THIS PART
	friend class MapIterator;

	private:
		struct Node
		{
			TElem data;
			int next;
			int previous;

		};
		Node* array;
		int capacity;
		int length;
		int head;
		int tail;
		int firstFree;
		int allocate_node();
		void deallocate_node(int position);
		void resize();
		

	public:

	// implicit constructor
	Map();

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	TValue add(TKey c, TValue v);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	TValue search(TKey c) const;

	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	TValue remove(TKey c);

	//returns the number of pairs (key,value) from the map
	int size() const;

	//checks whether the map is empty or not
	bool isEmpty() const;

	//returns an iterator for the map
	MapIterator iterator() const;

	// destructor
	~Map();

	TKey maxKey() const;

	

};



