#pragma once
#include "Domain.h"
#include <vector>
class Repository
{
private:
	std::vector<Biologist> biologists;
	std::vector<Bacterium> bacteriums;
public:
	Repository() {
		read_bacteria_from_file();
		 read_biologists_from_file();
	};
	~Repository() {};
	void read_bacteria_from_file();
	void read_biologists_from_file();
	
	std::vector<Bacterium>& get_bacteriums() { return bacteriums; };
	std::vector<Biologist>& get_biologists() { return biologists; };
	//std::vector<Bacterium>& get_bacteriums_it_studies_sorted_by_name(Biologist& biologist);
};