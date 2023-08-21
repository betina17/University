#include "Repository.h"
#include <fstream>
#include <sstream>
void DriversRepository::read_drivers_from_file()
{
	std::fstream fin("drivers.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream ss(line);
		std::string name;
		std::string x;
		std::string y;
		std::string score;
		getline(ss, name, '|');
		getline(ss, x, ',');
		getline(ss, y, '|');
		ss >> score;
		std::pair<int, int> location = { stoi(x), stoi(y) };
		Driver d(name, location, stoi(score));
		this->drivers.push_back(d);

	}

}
void ReportsRepository::read_reports_from_file()
{
	std::fstream fin("reports.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream ss(line);
		std::string description;
		std::string reporter;
		std::string x;
		std::string y;
		std::string validation_status;
		getline(ss, description, '|');
		getline(ss, reporter, '|');
		getline(ss, x, ',');
		getline(ss, y, '|');
		ss >> validation_status;
		std::pair<int, int> location = { stoi(x), stoi(y) };
		Report r(description, reporter, location, stoi(validation_status));
		this->reports.push_back(r);
	}
}