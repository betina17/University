#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	current_node = d.head;
}
//theta(1)

void MapIterator::first() {
	
		current_node = map.head;
	
}
//theta(1)

void MapIterator::next() {
	if (valid())
		current_node = map.array[current_node].next;
	else
		throw std::exception();
}
//theta(1)


TElem MapIterator::getCurrent(){
	if(valid())
		return map.array[current_node].data;
	else
		throw std::exception();
}
//theta(1)

bool MapIterator::valid() const {
	if (current_node != -1)
		return true;
	return false;
}
//theta(1)


