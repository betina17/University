#include <vector>
#include <string>
#include "Car.h"
#pragma once
#include <fstream>
#include <sstream>
class CarRepository
{  
private:
	std::vector<Car> cars;

public:
	
	void read_from_file();
	std::vector<Car>& get_cars();

	
};