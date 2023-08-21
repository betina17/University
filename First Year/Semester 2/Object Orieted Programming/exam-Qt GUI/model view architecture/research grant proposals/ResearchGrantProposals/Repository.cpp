#include "Repository.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>
void Repository::read_researchers_from_file()
{
	std::ifstream fin("Researchers.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, position;
		std::getline(string_line, name, '|'); //are nevoie de char ca delimitator, nu de string (const char[dimension]
		//adica string vazut ca vector de charuri) de aia pun '|', si nu "|"
		std::getline(string_line, position, '|');
		Researcher researcher = Researcher(name, position);
		researchers.push_back(researcher);
	}
	fin.close();
}
std::vector<Researcher>& Repository::get_researchers()
{
	return researchers;
}

void Repository::read_ideas_from_file()
{
	std::ifstream fin("Ideas.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string title, description, status, creator;
		int duration;
		std::getline(string_line, title, '|');
		std::getline(string_line, description, '|');
		std::getline(string_line, status, '|');
		std::getline(string_line, creator, '|');
		string_line >> duration;
		Idea idea = Idea(title, description, status, creator, duration);
		ideas.push_back(idea);

	}
	fin.close();
}
std::vector<Idea>& Repository::get_ideas()
{
	return ideas;
}