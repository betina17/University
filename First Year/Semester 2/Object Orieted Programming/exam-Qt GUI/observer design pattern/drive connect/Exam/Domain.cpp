#include "Domain.h"

Driver::Driver(std::string name, std::pair<int, int> current_location, int score)
{
	this->name = name;
	this->current_location = current_location;
	this->score = score;
}
Driver::Driver()
{
	this->name = "";
	this->current_location = { 0,0 };
	this->score = 0;
}

Report::Report()
{
	this->description = "";
	this->reporter = "";
	this->exact_location = { 0,0 };
	this->validation_status = false;
}
Report::Report(std::string const description, std::string const reporter, std::pair<int, int> exact_location, bool validation_status)
{
	this->description = description;
	this->reporter = reporter;
	this->exact_location = exact_location;
	this->validation_status = validation_status;
}
