#include "Repository.h"
#pragma once
class Service
{
private:
	Repository repo;
public:
	Repository& get_repo();
	vector<Food> sort_ascending_by_category_and_name();
};