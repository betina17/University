#pragma once
#include "Domain.h"
#include <vector>
class User_Interface
{
private:
	std::vector<TrenchCoat> data_base; //aici imi apeleaza constructorul gol by default
	std::vector<TrenchCoat> shopping_basket;
public:
	User_Interface() {};
	
	//mai am nvoie de astia? DA
	void start_menu();
	void generate_10_random_trench_coats();
	void display_shopping_basket();
};

