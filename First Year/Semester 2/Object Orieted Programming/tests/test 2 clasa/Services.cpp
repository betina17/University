#include "Services.h"

void Services::add_department(Hospital_Departments* department)
{
	Hospital_Departments.push_back(department);
}

vector<Hospital_Departments*> Services::get_all_departments()
{
	return vector<Hospital_Departments*>();
}
