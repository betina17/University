#include "Domain.h"
#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
class Repository {
private:
	vector<Food> Shopping_list;
public:
	void read_from_file();
	vector<Food>& get_shopping_list();
};