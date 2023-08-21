#include "Service.h"

Repository& Service::get_repo()
{
	return repo;
}

vector<Food> Service::sort_ascending_by_category_and_name()
{
	vector<Food> shopping_list = repo.get_shopping_list();
	for (int i = 0; i < shopping_list.size() - 1; i++)
		for (int j = i + 1; j < shopping_list.size(); j++)
			if (shopping_list[i].get_category() > shopping_list[j].get_category())
				swap(shopping_list[i], shopping_list[j]);
			else if (shopping_list[i].get_category() == shopping_list[j].get_category())
				if (shopping_list[i].get_name() > shopping_list[j].get_name())
					swap(shopping_list[i], shopping_list[j]);
	return shopping_list;
}
