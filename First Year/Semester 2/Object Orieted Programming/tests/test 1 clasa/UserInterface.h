#pragma once
#include "Services.h"
#include <string>
class UserInterface 
{
private:
	Services services;
public:
	UserInterface() {};
	void start_menu();
	void generate_random_players();

};