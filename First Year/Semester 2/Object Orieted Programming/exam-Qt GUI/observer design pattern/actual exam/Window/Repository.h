#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <sstream>
class Repository
{
private:
	std::vector<Event> events;
	std::vector<Person> persons;
public:
	Repository()
	{
		read_events_from_file();
		read_persons_from_file();
	};
	~Repository() {};
	void read_events_from_file();
	void read_persons_from_file();
	std::vector<Event>& get_events() { return events; };
	std::vector<Person>& get_persons() { return persons; };
};