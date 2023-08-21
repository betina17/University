#pragma once
#include <string>
class Event
{
private:
	std::string organiser, name, description, date;
	std::pair<int, int> location;
public:
	Event() {};
	Event(std::string organiser = "", std::string name = "", std::string description = "", std::string date = "", std::pair<int, int> location = {0,0})
	{
		this->organiser = organiser;
		this->name = name;
		this->description = description;
		this->date = date;
		this->location = location;
	}
	~Event() {};
	std::string& get_organiser() { return organiser; };
	std::string& get_name() { return name; };
	std::string& get_description() { return description; };
	std::string& get_date() { return date; };
	std::pair<int,int>& get_location() { return location; };
};
class Person
{
private:
	std::string name;
	std::pair<int, int> location;
	bool organiser_status;
public:
	Person() {};
	Person(std::string name = "", std::pair<int, int> location = { 0,0 }, bool organiser_status = 0)
	{
		this->name = name;
		this->location = location;
		this->organiser_status = organiser_status;
	};
	~Person() {};
	std::string& get_name() { return name; };
	std::pair<int, int>& get_location() { return location; };
	bool& get_organiser_status() { return organiser_status; };


};