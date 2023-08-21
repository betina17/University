#include "Repository.h"
#include <string>
Repository::Repository()
{
	this->size = 0;
	this->capacity = 0;
}
Repository::Repository(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
}
Repository::Repository(const Repository& repository)
{
	this->size = repository.size;
	this->capacity = repository.capacity;
	this->elements = new Player[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = repository.elements[i];
}
Repository& Repository::operator=(Repository& repository)
{
	this->size = repository.size;
	this->capacity = repository.capacity;
	delete[] this->elements;
	this->elements = new Player[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = repository.elements[i];
	return *this;
}
void Repository::resize()
{
	capacity = 2 * capacity;
	Player* new_elements = new Player[capacity];
	for (int i = 0; i < size; i++)
		new_elements[i] = elements[i];
	delete[] elements;
	elements = new_elements;
}
std::string Repository::add_player_repo(Player new_player)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(new_player.get_name(), elements[i].get_name()) == 0)
		{	
			return "Player already exists!"
		}
	}
	if (size == capacity)
		resize();
	elements[size] = new_player;
	size++;
	return "Player successfully added!";
}
std::string Repository::display_all()
{
	for (int i = 0; i < size; i++)
		std::count << elements[i].display_player();
}