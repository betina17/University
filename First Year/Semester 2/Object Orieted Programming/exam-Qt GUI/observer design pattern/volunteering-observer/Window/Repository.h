#pragma once
#include "Domain.h"
#include <vector>
class DepartmentsRepository
{
private:
	std::vector<Department> departments;
public:
	DepartmentsRepository() { };
	~DepartmentsRepository() {};
	void read_departments_from_file();
	std::vector<Department>& get_departments() { return departments; };
	
};
class VolunteersRepository
{
private:
	std::vector<Volunteer> volunteers;
public:
	VolunteersRepository() { };
	~VolunteersRepository() {};
	void read_volunteers_from_file();
	std::vector<Volunteer>& get_volunteers() { return volunteers; };
};