#pragma once
#include "Domain.h"
#include <vector>
#include "Repository.h"
#include "Validator.h"
class User_Interface
{
private:
	std::vector<TrenchCoat> data_base; //aici imi apeleaza constructorul gol by default
	std::vector<TrenchCoat> shopping_basket;
public:
	User_Interface() {};
	//mai am nvoie de astia? DA
	void start_menu();
	
};


