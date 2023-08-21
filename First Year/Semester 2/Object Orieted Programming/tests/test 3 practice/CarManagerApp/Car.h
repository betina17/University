#pragma once
#include <string>
class Car
{
private:
	std::string manufacturer, model, colour;
	int year_of_fabrication;
public:

	Car(std::string manufacturer, std::string model, int year_of_fabrication, std::string colour);
	std::string get_manufacturer();
	std::string get_model();
	std::string get_colour();
	//pun const pt ca parametrii nu se modifica in constructor
	//mai aveam copy constructor si assignement operator, dar nu mai am nevoie de ele
	//empty constructor ai by default, si destructor la fel
	//the data is read from the file into memory only at application start,and then, every change that I make in memory I guess I should make in the file-so
	//I rewrite the file after I
	//add, remove, update, that;s what I did for a7, but without the sorting by manufacturer change. that i will only make in memory.
	//at this test, I only have the sorting problem, so I won't rewrite the file, so therefore I will only have a read from file function
	//without a write to file function
};