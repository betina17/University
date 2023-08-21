#include "Validator.h"
#include <cctype>

void TrenchCoat_Validator::validate_size(const std::string& size)
{
	if (size != "s" && size != "S" && size != "m" && size != "M" && size != "l" && size != "L" && size != "xl" && size != "XL" && size != "xxl" && size != "XXL")
		throw TrenchCoat_Exception("Invalid size!Please try again!\n");
}

void TrenchCoat_Validator::validate_colour(const std::string& colour)
{
	if (colour != "red" && colour != "Red" && colour != "blue" && colour != "Blue" && colour != "black" && colour != "Black" && colour != "white" && colour != "White" && colour != "yellow" && colour != "Yellow")
		if (colour != "pink" && colour != "Pink" && colour != "orange" && colour != "Orange" && colour != "brown" && colour != "Brown" && colour != "green" && colour != "Green" && colour != "purple" && colour != "Purple" && colour != "gray" && colour != "Gray")
			throw TrenchCoat_Exception("Invalid colour!Please try again!\n");
}

void TrenchCoat_Validator::validate_price(const std::string& price)
{
	int int_price;
	try 
	{	
		int_price = std::stoi(price);
	}
	catch (std::exception& e) 
	{
		throw TrenchCoat_Exception("Invalid price!Please try again!\n");

	}
	
	if (int_price < 0 || int_price > 100000)
		throw TrenchCoat_Exception("Invalid price!Please try again!\n");
}

void TrenchCoat_Validator::validate_quantity(const std::string& quantity)
{
	int int_quantity;
	try {
		int_quantity = std::stoi(quantity);
	}
	catch(std::exception& e){
		throw TrenchCoat_Exception("Invalid quantity!Please try again!\n");
	}
	if (int_quantity < 0 || int_quantity > 100000)
		throw TrenchCoat_Exception("Invalid quantity!Please try again!\n");
}

void TrenchCoat_Validator::validate_photograph(const std::string& photograph)
{
	if (photograph.find("https://") != 0)
		throw TrenchCoat_Exception("Invalid photograph!Please try again!\n");
}

void TrenchCoat_Validator::validate_trench_coat(TrenchCoat& trench_coat)
{
	validate_size(trench_coat.get_size());
	validate_colour(trench_coat.get_colour());
	validate_price(std::to_string(trench_coat.get_price()));
	validate_quantity(std::to_string(trench_coat.get_quantity()));
	validate_photograph(trench_coat.get_photograph());
}



