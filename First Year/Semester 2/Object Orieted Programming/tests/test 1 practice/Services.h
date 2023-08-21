#pragma once
#include "Repository.h"
#include <string>
class Services
{
private:
	Repository repository;
public:
	Services();
	void add_service(Car new_car);
	void remove_service();
	void sort_by_manufacturer_and_model();
	Repository& get_repo() { return this->repository; }
	
};