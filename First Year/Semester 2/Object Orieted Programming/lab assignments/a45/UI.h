#pragma once
#include "Repository.h"
class User_Interface
{
private:
	DynamicArray<TrenchCoat> dynamic_array; //aici imi apeleaza constructorul gol by default
	DynamicArray<TrenchCoat> shopping_basket;
public:
	User_Interface();
	
	//mai am nvoie de astia? DA
	DynamicArray<TrenchCoat> get_repository() { return this->dynamic_array; }
	void start_menu();
	void generate_10_random_trench_coats();
};

