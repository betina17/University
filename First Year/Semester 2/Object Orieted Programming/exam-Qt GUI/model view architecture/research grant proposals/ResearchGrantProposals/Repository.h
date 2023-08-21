#pragma once
#include <vector>
#include <string>
#include "Domain.h"
class Repository
{
private:
	std::vector<Researcher> researchers;
	std::vector<Idea> ideas;
public:
	Repository() 
	{
		read_ideas_from_file();
		read_researchers_from_file();
	};
	void read_researchers_from_file();
	void read_ideas_from_file();
	~Repository() {};
	std::vector<Researcher>& get_researchers();
	std::vector<Idea>& get_ideas();
};
