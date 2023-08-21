#include "Domain.h"
#include <string>
#include <Windows.h>
#include <cstring>
#include <vector>
TrenchCoat::TrenchCoat()
{
	this->price = 0;
	this->quantity = 0;
	this->size = "";
	this->colour = "";
	this->photograph = "";
}
TrenchCoat::TrenchCoat( const std::string& size,const std::string& colour,const int& price,const int& quantity,const std::string& photograph)
{
	this->price = price;
	this->quantity = quantity;
	this->size = size;
	this->colour = colour;
	this->photograph = photograph;
}
TrenchCoat::TrenchCoat(const TrenchCoat& trench_coat)
{
	this->price = trench_coat.price;
	this->quantity = trench_coat.quantity;
	this->size = trench_coat.size;
	this->colour = trench_coat.colour;
	this->photograph = trench_coat.photograph;
}

std::string TrenchCoat::display_as_string()
{
	return "\nThis trench coat comes in size " + size  + ", colour " + colour + " at the price of " + std::to_string(price) + " euros" + ", the quantity is " + std::to_string(quantity);
}

void TrenchCoat::ShowImage()
{
	ShellExecuteA(NULL, "open", photograph.c_str(),NULL, NULL, SW_SHOWMAXIMIZED);
}


std::istream& operator>>(std::istream& is, TrenchCoat& trench_coat)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens;
	char* token = strtok(const_cast<char*>(line.c_str()), ",");
	while (token != NULL)
	{
		tokens.push_back(token);
		token = strtok(NULL, ",");
	}
	if (tokens.size() != 5)
		return is;
	trench_coat.size = tokens[0];
	trench_coat.colour = tokens[1];
	trench_coat.price = std::stoi(tokens[2]);
	trench_coat.quantity = std::stoi(tokens[3]);
	trench_coat.photograph = tokens[4];
	return is;
}	


std::ostream& operator<<(std::ostream& os, TrenchCoat& trench_coat)
{
	os << trench_coat.size << "," << trench_coat.colour << "," << trench_coat.price << "," << trench_coat.quantity << "," << trench_coat.photograph << '\n';
	return os;
}



