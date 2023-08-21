#include "Repository.h"

void Repository::read_from_file()
{
	ifstream file("shopping_list.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string category, name, quantity;
		getline(ss, category, '|');
		getline(ss, name, '|');
		getline(ss, quantity, '|');
		Food food(category, name, stoi(quantity));
		Shopping_list.push_back(food);
	}
	file.close();
}

vector<Food>& Repository::get_shopping_list()
{
	return Shopping_list;
}
