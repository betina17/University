#pragma once
using namespace std;
#include <string>
class Food
{
private:
	string category, name;
	int quantity;
public:
	Food(string category, string name, int quantity);
	string get_category();
	string get_name();
	int get_quantity();
	
};