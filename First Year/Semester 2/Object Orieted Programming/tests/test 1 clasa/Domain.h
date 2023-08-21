#pragma once
#include <string>
class Player
{
private:
	std::string name, nationality, team;
	int goals;
public:
	Player();
	Player(const std::string name, const std::string nationality, const std::string team, const int goals);
	std::string display_player();
	std::string get_name() { return name; }
	
};