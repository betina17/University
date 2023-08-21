#pragma once
#include "Services.h"
class UserInterface
{
private:
	Services services;

public:
	UserInterface() {};  //efectiv chiar daca constructorul e gol trb macar sa am functia de cosntructor goala, nu pot doar headerul
	void generate_5_random_cars();
	void start_menu();
	Services& get_services() { return this->services; }
};