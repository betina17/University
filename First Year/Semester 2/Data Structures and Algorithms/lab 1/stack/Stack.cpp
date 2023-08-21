#include "Stack.h"
#include <exception>


using namespace std;


Stack::Stack() {
	//TODO - Implementation
	this->capacity = 100;
	this->topIndex = -1;
	this->elements = new TElem[capacity];
}

void Stack::resize() {
	TElem* new_elems = new TElem[2 * capacity];
	for (int i = 0; i < capacity; i++)
		new_elems[i] = elements[i];
	capacity = 2 * capacity;
	delete[] elements;
	elements = new_elems;
}

void Stack::push(TElem e) {
	//TODO - Implementation
	if (topIndex == capacity - 1)
	{
		resize();
		topIndex++;
		elements[topIndex] = e;
	}
	else
	{ 
		topIndex++;
		elements[topIndex] = e;
	}
}

TElem Stack::top() const {
	//TODO - Implementation
	
	if (isEmpty() == true)
		throw exception(); //NULL_TELEM
	return elements[topIndex];
}

TElem Stack::pop() {
	//TODO - Implementation
	if (isEmpty() == true)
		throw exception(); //NULL_TELEM
	topIndex--;
	return elements[topIndex + 1];
}


bool Stack::isEmpty() const {
	if (topIndex == -1)
		return true;
	else
		return false;
}

Stack::~Stack() {
	//TODO - Implementation
	delete[] elements;
}
