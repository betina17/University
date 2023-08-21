#include "Domain.h"
#include <string>
bool Neonatal_Unit::is_efficient()
{
	if (average_grade > 8)
		return true;
	return false;
}

string Neonatal_Unit::toString()
{
	return "Neonatal unit has an average grade of " + this->average_grade.to_string();
}

bool Surgery::is_efficient()
{
	if (number_of_doctors > 10)
		return true;
	return false;
}

string Surgery::toString()
{
	return "Surgery has a number of doctors equal to " + number_of_doctors.to_string();
}

Hospital_Departments::Hospital_Departments()
{
	this->hospital_name = "";
	this->number_of_doctors = 0;
}
