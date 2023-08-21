#include "Repository.h"

void Repository::read_events_from_file()
{
	std::ifstream fin("events.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string organiser, name, description, date, latitude, longitude;
		std::pair<int, int> location;
		getline(string_line, organiser, '|');
		getline(string_line, name, '|');
		getline(string_line, description, '|');
		getline(string_line, latitude, ',');
		getline(string_line, longitude, '|');
		getline(string_line, date, '|');
		int latitude1 = stoi(latitude);
		int longitude2 = stoi(longitude);
		location = std::make_pair(latitude1, longitude2);
		Event event(organiser, name, description, date, location);
		events.push_back(event);


	}
	fin.close();
}

void Repository::read_persons_from_file()
{

	std::ifstream fin("persons.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, latitude, longitude, organiser_status;
		std::pair<int, int> location;
	
		getline(string_line, name, '|');
		getline(string_line, latitude, ',');
		getline(string_line, longitude, '|');
		getline(string_line, organiser_status, '|');
		int latitude1 = stoi(latitude);
		int longitude2 = stoi(longitude);
		location = std::make_pair(latitude1, longitude2);
		int organiser_status1 = stoi(organiser_status);
		Person person(name, location, organiser_status1);
		persons.push_back(person);

	}
	fin.close();
}
