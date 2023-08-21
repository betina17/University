#include "Domain.h"

Food::Food(string category, string name, int quantity)
{
    this->category = category;
    this->name = name;
    this->quantity = quantity;
}

string Food::get_category()
{
    return category;
}

string Food::get_name()
{
    return name;
}

int Food::get_quantity()
{
    return quantity;
}
