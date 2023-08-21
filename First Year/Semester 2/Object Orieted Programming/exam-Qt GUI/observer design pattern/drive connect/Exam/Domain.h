#pragma once
#include <string>
class Driver
{
private:
	std::string name;
	std::pair<int, int> current_location;
	int score;
public:
	Driver(std::string name, std::pair<int, int> current_location, int score);
	Driver();
	~Driver() {};
	std::pair<int, int>& get_current_location() { return this->current_location; };
	int& get_score() { return this->score; };
	std::string& get_name() { return this->name; };
};
class Report
{
private:
	std::string description, reporter;
	std::pair<int, int> exact_location;
	bool validation_status;
public:
	Report();
	Report(std::string const description, std::string const reporter, std::pair<int, int> exact_location, bool validation_status);
	~Report() {};
	std::string& get_description() { return this->description; };
	std::string& get_reporter() { return this->reporter; };
	int get_validation_status() { return this->validation_status; };
	std::pair<int, int>& get_exact_location() { return this->exact_location; };
};
