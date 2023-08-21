#include "Domain.h"
#include <string>
#include <Windows.h>
TrenchCoat::TrenchCoat()
{
	this->price = 0;
	this->quantity = 0;
	this->size = "";
	this->colour = "";
	this->photograph = "";
}
TrenchCoat::TrenchCoat( const std::string& size,const std::string& colour,const int& price,const int& quantity,const std::string& photograph)
{
	this->price = price;
	this->quantity = quantity;
	this->size = size;
	this->colour = colour;
	this->photograph = photograph;
}
TrenchCoat::TrenchCoat(const TrenchCoat& trench_coat)
{
	this->price = trench_coat.price;
	this->quantity = trench_coat.quantity;
	this->size = trench_coat.size;
	this->colour = trench_coat.colour;
	this->photograph = trench_coat.photograph;
}

std::string TrenchCoat::display_as_string()
{
	return "\nThis trench coat comes in size " + size  + ", colour " + colour + " at the price of " + std::to_string(price) + " euros" + ", the quantity is " + std::to_string(quantity);
}

void TrenchCoat::ShowImage()
{
	ShellExecuteA(NULL, "open", photograph.c_str(),NULL, NULL, SW_SHOWMAXIMIZED);
}


//bash = born again shell



