#pragma once
#include "Domain.h"
#include<string>

class Repository
{
private:
	int  size, capacity;
	Player* elements;
	void resize();
public:
	Repository();
	Repository(int capacity);
	Repository(const Repository& repository);
	Repository& operator=(Repository& repository);
	Player& get_player(int position) { return this->elements[position]; }
	std::string add_player_repo(Player new_player);
	std::string display_all();

};