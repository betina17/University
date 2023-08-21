#include "Repository.h"
#include <string>
Repository::Repository()
{
	capacity = 100;
	size = 0;
	elements = new Car[this->capacity];
}
Repository::Repository(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new Car[this->capacity];
}
Repository::Repository(Repository& repository)
{
	this->capacity = repository.capacity;
	this->size = repository.size;
	this->elements = new Car[capacity];
	for (int i = 0; i < size; i++)
		this->elements[i] = repository.elements[i];
}
Repository& Repository::operator=(const Repository& repository)
{
	this->capacity = repository.capacity;
	this->size = repository.size;
	delete[] this->elements;
	this->elements = new Car[capacity];
	for (int i = 0; i < size; i++)
		this->elements[i] = repository.elements[i];
	return *this;
}
Repository::~Repository()
{
	this->capacity = 0;
	this->size = 0;
	delete[] this->elements;
}
void Repository::add_repo(Car new_car)
{
	if (this->size == this->capacity)
		resize();
	elements[this->size] = new_car;
	this->size++;
}
void Repository::resize()
{
	this->capacity = 2 * this->capacity;  ///nu trb neap sa scriu this->capacity, dar ar fi bine sa folosesc this ca vad mai bine 
	Car* new_elements = new Car[this->capacity];
	for (int i = 0; i < this->capacity; i++)
		new_elements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = new_elements;
}