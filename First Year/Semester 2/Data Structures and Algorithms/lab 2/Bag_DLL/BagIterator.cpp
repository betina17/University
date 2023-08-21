#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	current_node = bag.head;
}

void BagIterator::first() {
	current_node = bag.head;
}


void BagIterator::next() {
	current_node = current_node->next;
}


bool BagIterator::valid() const {
	if(current_node == nullptr)
		return false;
	return true;
}



TElem BagIterator::getCurrent() const
{
	return current_node->element;
}
