#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm> //NECESAR PT SORT!!!!!
void Repository::read_bacteria_from_file()
{
	std::fstream fin("bacteria.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, species, list_of_diseases, size;
		getline(string_line, name, '|');
		getline(string_line, species, '|');
		getline(string_line, size, '|');
		getline(string_line, list_of_diseases, '|');
		int actual_size = stoi(size);
		Bacterium new_bacterium(name, species,actual_size,  list_of_diseases);
		bacteriums.push_back(new_bacterium);

		
	}
	fin.close();
}

void Repository::read_biologists_from_file()
{
	std::fstream fin("biologists.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, list_of_bacterial_species;
		getline(string_line, name, '|');
		getline(string_line, list_of_bacterial_species, '|');
		Biologist new_biologist(name, list_of_bacterial_species);
		biologists.push_back(new_biologist);
	}
	fin.close();
}



/*std::vector<Bacterium>& Repository::get_bacteriums_it_studies_sorted_by_name(Biologist& biologist)
{
	std::vector<Bacterium> bacteriums_studied_sorted_by_name;
	for (Bacterium& bacterium : bacteriums)
	{
		std::stringstream line(biologist.get_list_of_bacterial_species());
		std::string word;
		while (getline(line, word, ','));
		{
			if(bacterium.get_species() == word)
			{
				bacteriums_studied_sorted_by_name.push_back(bacterium);
				break;
		}
	}
	//am verificat pt fiecare bacterie daca specia ei se regaseste in lista de specii studiate de 
		//biolog
	std::sort(bacteriums_studied_sorted_by_name.begin(), bacteriums_studied_sorted_by_name.end(),
			[](Bacterium& bacterium1, Bacterium& bacterium2) {return bacterium1.get_name() > bacterium2.get_name(); });
	//se scrie simplu, fara vector = std::sort(vector.begin()....)
	return &bacteriums_studied_sorted_by_name;
}
*/