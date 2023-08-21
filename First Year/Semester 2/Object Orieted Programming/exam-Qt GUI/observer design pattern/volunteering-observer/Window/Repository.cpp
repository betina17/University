#include "Repository.h"
#include <fstream>
#include <sstream>

void DepartmentsRepository::read_departments_from_file()
{
	std::ifstream fin("departments.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, description;
		getline(string_line, name, '|');
		getline(string_line, description, '|');
		Department new_department(name, description);
		departments.push_back(new_department);
	}

}

void VolunteersRepository::read_volunteers_from_file()
{
	std::ifstream fin("volunteers.txt");
	std::string line;
	while (getline(fin, line))
	{
		std::stringstream string_line(line);
		std::string name, email, list_of_interests, department;
		getline(string_line, name, '|');
		getline(string_line, email, '|');
		getline(string_line, list_of_interests, '|');
		getline(string_line, department, '|');
		Volunteer new_volunteer(name, email, list_of_interests, department);
		volunteers.push_back(new_volunteer);
	}
}
