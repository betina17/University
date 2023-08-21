#pragma once
#include <string>
class Car
{
private:
	std::string manufacturer_name, model, colour;
	int year_of_fabrication;
public:
	Car();
	Car(const std::string& manufacturer_name, const std::string& model, const std::string& colour, const int& year_of_fabrication);
	std::string display_as_string();
};