#pragma once
#include "Repository.h"
#include <string>
class Services
{
private:
	Repository repository;
public:
	Services();
	void add_player_services(Player new_player);
	Repsoitory& get_repo() { return repository; }

};