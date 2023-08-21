#pragma once
#include <string>
#include <sstream>
class Biologist
{
private:
	std::string name, list_of_bacterial_species;
public:
	Biologist() {};
	Biologist(std::string name = "", std::string list_of_bacterial_species = "") :
		name{ name}, list_of_bacterial_species{ list_of_bacterial_species } {};
	~Biologist() {};
	std::string& get_name() { return name; };
	std::string& get_list_of_bacterial_species() { return list_of_bacterial_species; };
	int get_number_of_species_it_studies()
	{
		int counter=0;
		std::stringstream line(list_of_bacterial_species);
		std::string word;
		while (getline(line, word, ','));
			counter++;
			return counter + 1;
	};

};
class Bacterium
{
private:
	std::string name, species, list_of_diseases;
	int size;
public:
	Bacterium() {};
	Bacterium(std::string name = "", std::string species = "",  int size =0, std::string list_of_diseases = "") :
		name{ name }, species{ species }, list_of_diseases{ list_of_diseases }, size{ size } {};
	~Bacterium() {};
	std::string& get_name() { return name; };
	std::string& get_species() { return species; };
	std::string& get_list_of_diseases() { return list_of_diseases; };
	int& get_size() { return size; };
};