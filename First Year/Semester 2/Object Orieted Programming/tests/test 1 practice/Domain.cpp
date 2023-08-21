#include "Domain.h"
#include <string>
Car::Car()
{
	manufacturer_name = "";
	model = "";
	colour = "";
	year_of_fabrication = 0;
}
Car::Car(const std::string& manufacturer_name, const std::string& model, const std::string& colour, const int& year_of_fabrication)
{
	this->manufacturer_name = manufacturer_name;
	this->model = model;
	this->colour = colour;
	this->year_of_fabrication = year_of_fabrication;
}
std::string Car::display_as_string()
{
	return this->manufacturer_name + " | " + this->model + " | " + std::to_string(this->year_of_fabrication) + " | " + this->colour;
}

