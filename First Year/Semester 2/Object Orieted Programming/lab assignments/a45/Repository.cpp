#include "Repository.h"
#include <iostream>

template <typename Telem>
DynamicArray<Telem>::DynamicArray()
{
	this->size = 0;
	this->capacity = 100;
}
template<typename Telem>
void DynamicArray<Telem>::display_all_elements_in_repo()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->elements[i].display_as_string();
	}
}
template <typename Telem> ///Telem=Template element
DynamicArray<Telem>::DynamicArray(int capacity)
{
	size = 0;
	this->capacity = capacity;
	elements = new Telem[this->capacity];
}
template <typename Telem>
DynamicArray<Telem>::DynamicArray(const DynamicArray& dynamic_array)
{
	this->size = dynamic_array.size;
	this->capacity = dynamic_array.capacity;
	//aici nu am ce elem sa sterg pt ca asta e apelat when I asssign to a new created object an existing project, iar the new object nu a avut de dinainte elemente alocate dinamic
	this->elements = new Telem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = dynamic_array.elements[i];
	//nu retrunez nimic ca nu are return type
}
template <typename Telem>
DynamicArray<Telem>& DynamicArray<Telem>::operator=(const DynamicArray& dynamic_array)
{
	size = dynamic_array.size;
	capacity = dynamic_array.capacity;
	delete[] elements; //ii stergi elementele de dinainte, pe care le inlocuiesti cu cele de la noul obiect
	elements = new Telem[this->capacity];
	for (int i = 0; i < this->size; i++)
		elements[i] = dynamic_array.elements[i];
	return *this; //pt ca are return type adresa spre un obiect Telem
}
template <typename Telem>
DynamicArray<Telem>::~DynamicArray()
{
	this->size = 0;
	this->capacity = 0;
	delete[] this->elements;
}
template <typename Telem>
void DynamicArray<Telem>::resize()
{
	this->capacity *= 2;
	Telem* new_elements = new Telem[this->capacity];
	for (int i = 0; i < this->size; i++)
		new_elements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = new_elements;
}
template <typename Telem>
int DynamicArray<Telem>::search_element_in_repo(std::string size, std::string colour)
{
	int position = -1;
	for (int i = 0; i < this->size; i++)
		if ((this->elements[i].get_size() == size) && (this->elements[i].get_colour() == colour))
		{
			position = i;
			break;
		}
	return position;
}

template <typename Telem>
void DynamicArray<Telem>::add_element(Telem element)
{	
		if (this->size == this->capacity)
			this->resize();
		this->elements[this->size] = element;
		this->size++;
	
}
template <typename Telem>
void DynamicArray<Telem>::delete_element(int position)
{	
	for (int i = position; i < this->size - 1; i++)
		this->elements[i] = this->elements[i + 1];
	this->size--;
}
template <typename Telem>
void DynamicArray<Telem>::update_element(Telem element)
{
	int position = -1;
	/*for (int i = 0; i < this->size; i++)
		if (this->elements[i] == element)
		{
			position = i;
			break;
		}*/
	if (position == -1)
		return;
	this->elements[position] = element;
}
template <typename Telem>
Telem DynamicArray<Telem>::get_element(int position)
{
	return elements[position];
}
template class  DynamicArray<TrenchCoat>;


























//template class  DynamicArray<Coat>;
//FOARTE IMPORTANTA CHESTIA ASTA: trebe sa scrii asta pt fiecaare tip de obiect pe care il folosesti