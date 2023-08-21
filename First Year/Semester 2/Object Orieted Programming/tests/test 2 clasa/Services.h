#include "Domain.h"
#pragma once
#include <vector>
using namespace std;
class Services
{
public:
	Services() {};
	~Services() {};
	vector<Hospital_Departments*> hospital_departments;
	void add_department(Hospital_Departments* departement);
	vector<Hospital_Departments*> get_all_departments();

};