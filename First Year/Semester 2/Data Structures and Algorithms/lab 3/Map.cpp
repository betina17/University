#include "Map.h"
#include "MapIterator.h"

Map::Map() {

	this->capacity = 100;
	this->length = 0;
	this->head = -1;
	this->tail = -1;
	this->firstFree = 0;
	this->array = new Node[capacity];
	for (int i = 1; i < capacity-1; i++)
	{
		array[i].next = i+1;
		array[i].previous = i-1;
	}
	array[0].next = 1;
	array[0].previous = -1;
	array[capacity - 1].next = -1;
	array[capacity - 1].previous = capacity - 2;

}
//Theta(capacity)-this is for all cases. 


Map::~Map() {
	
	delete[] array;
}

TKey Map::maxKey() const
{ //finds and returns the maximum key from the Map. if the map is empty, it returns NULL_TKEY
	if (isEmpty())
		return NULL_TKEY;
	else
	{
		int current = head;
		int max_key = INT_MIN;
		while (current != -1)
		{
			if (array[current].data.first > max_key)
				max_key = array[current].data.first;
			current = array[current].next;
		}
		return max_key;
		
		
	}
}
//Best case:Theta(1)-cazul specific in care nu gaseste elementul
//Worst case:Theta(capacity)-cazul specific in care parcurge toata lista
//Average case:O(capacity)-nu e un caz specific, de aia e average, nu e nici best nu e nici worst, e cumva o medie intre ele.O comes from overall.
//O(capacity) inseamna ca se poate intampla sa am intre 1 si capacity iteratii, adica intre best si worst case

int Map::allocate_node()
{
	if (firstFree == -1) { //acelasi lucru cu length == capacity
		resize();
		firstFree = length;
	}
	int newFreePos = firstFree;
	firstFree = array[firstFree].next;
	length++;
	return newFreePos;
}
//Theta(1)

void Map::deallocate_node(int position)
{
	if (position == head)
	{

		if (position == tail)
		{
			head = -1;
			tail = -1;
		}
		else
		{
			head = array[head].next;
			array[head].previous = -1;
		}
	}
	else if (position == tail)
	{
		tail = array[tail].previous;
		array[tail].next = -1;
	}

	else {
		array[array[position].previous].next = array[position].next;
		array[array[position].next].previous = array[position].previous;
	}
	array[position].next = firstFree;
	array[position].previous = -1;
	firstFree = position;
	length--;
}
//Theta(1)

TValue Map::add(TKey c, TValue v){ 
		//adds a pair(key, value) to the map
		//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
		//if the key does not exist, a new pair is added and the value null is returned
	TElem pair = std::make_pair(c, v);
	int current = head;
	if (isEmpty())
	{
		int newNodePos = allocate_node();
		array[newNodePos].data = pair;
		head = newNodePos;
		tail = newNodePos;
		array[newNodePos].next = -1;
		array[newNodePos].previous = -1;
		return NULL_TVALUE;
	}
	while (current != -1) {
		if (array[current].data.first == c) {
			TValue oldValue = array[current].data.second;
			array[current].data.second = v;
			return oldValue;
		}
		current = array[current].next;
	}
	if (current == -1) {
		int newNodePos = allocate_node();
		array[newNodePos].data = pair;
		array[newNodePos].previous = tail;
		array[newNodePos].next = -1;
		array[tail].next = newNodePos;
		tail = newNodePos;
	}
	return NULL_TVALUE;

}
//Best case:Theta(1)
//Worst case:Theta(capacity)
//Average case: O(capacity)

TValue Map::search(TKey c) const{
	int current_node = head;
	while (current_node != -1 && array[current_node].data.first != c) {
		current_node = array[current_node].next;
	}
	if (current_node != -1)
		return array[current_node].data.second;
	return NULL_TVALUE;
}
//best case:Theta(1)
//worst case:theta(capacity)
//average case: O(capacity)

TValue Map::remove(TKey c){
	//removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TVALUE otherwise
	int current = head;
	while (current != -1)
	{
		if (array[current].data.first == c)
		{
			TValue value = array[current].data.second;
			deallocate_node(current);
			return value;

		}
		current = array[current].next;
	}
	return NULL_TVALUE;

}
//best case:Theta(1)
//worst case:theta(capacity)
//average case: O(capacity)

int Map::size() const {
	
	return length;
}
//theta(1)

bool Map::isEmpty() const{
	if (length == 0)
		return true;
	return false;
}
//theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
//theta(1)
void Map::resize()
{
	capacity = 2 * capacity;
	Node* new_array = new Node[capacity];
	for (int i = 0; i < length; i++)
		new_array[i] = array[i];

	delete[] array;
	array = new_array;
	for (int i = length; i < capacity - 1; i++)
	{
		array[i].next = i + 1;
		array[i].previous = i - 1;
	}
	array[capacity - 1].next = -1;
	array[capacity - 1].previous = capacity - 2;

}
//theta(capacity)


