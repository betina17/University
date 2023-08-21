#include "Car.h"

Car::Car(std::string manufacturer,  std::string model, int year_of_fabrication, std::string colour)
{
	this->manufacturer = manufacturer;
	this->model = model;
	this->colour = colour;
	this->year_of_fabrication = year_of_fabrication;
}

std::string Car::get_manufacturer()
{
	return manufacturer;
}

std::string Car::get_model()
{
	return model;
}

std::string Car::get_colour()
{
	return colour;
}
