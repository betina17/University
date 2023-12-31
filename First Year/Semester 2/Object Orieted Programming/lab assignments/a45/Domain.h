#pragma once
#include <string>
///aici pot avea mai multe clase care sa defineasca mai multe tipuri de obiecte
class TrenchCoat
{
private:
	int price, quantity;
	std::string size, colour, photograph; ///la tot ce iau din librarii pun std in fata pt ca nu mai folosesc using namespace std
	
public:
	TrenchCoat();  ///empty constructor
	TrenchCoat(const std::string& size, const std::string& colour, const int& price, const int& quantity, const std::string& photograph); ///constructor with given parameters
	TrenchCoat(const TrenchCoat& trench_coat); ///copy constructor	
	/// <summary>
	///i don't need a destructor for this class because i don t have any dynamically allocated memory in this class, in repo am nevoie
	int get_price() { return this->price; }
	int get_quantity() { return this->quantity; }
	std::string  get_size() { return this->size; }
	std::string get_colour() { return this->colour; }
	std::string get_photograph() { return this->photograph; }
	void set_price(int price) { this->price = price; }
	void set_quantity(int quantity) { this->quantity = quantity; }
	void set_photograph(std::string photograph) { this->photograph = photograph; }
	std::string display_as_string();  ///o sa am mai multe stringuri de afisat oricum
	void ShowImage();



};