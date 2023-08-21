#include "Domain.h"
#include <string>
Player::Player()
{
	this->name = "";
	this->nationality = "";
	this->team = "";
	this->goals = 0;
}
Player::Player(const std::string name,const std::string nationality,const std::string team,const int goals);
{
	this->name = name;
	this->nationality = nationality;
	this->team = team;
	this->goals = goals;
}
std::string Player::display_player()
{
	return name + " | " + nationality + " | " + team + " | " + std::to_string(goals);
}