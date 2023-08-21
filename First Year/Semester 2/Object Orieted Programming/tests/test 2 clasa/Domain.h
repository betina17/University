#include <string>
using namespace std;
#pragma once 

class Hospital_Departments {
protected:
	string hospital_name;
	int number_of_doctors;
public:
	Hospital_Departments();
	~Hospital_Departments() {};
	Hospital_Departments(string hospital_name, int number_of_doctors)
	{
		this->hospital_name = hospital_name;
		this->number_of_doctors = number_of_doctors;
	}
	virtual bool is_efficient() = 0;
	virtual string toString() = 0;

	
};

class Neonatal_Unit : public Hospital_Departments{
public:
	Neonatal_Unit(string hospital_name, int number_of_doctors,double average_grade) : Hospital_Departments(string hospital_name, int number_of_doctors)
	{
		this->average_grade = average_grade;

	}
	double average_grade;
	virtual bool is_efficient() override;
	virtual string toString() override;
	
};

class Surgery : public Hospital_Departments
{
private:
	int nr_of_patients;
public:
	Surgery(string hospital_name, int number_of_doctors,int nr_of_patients) : Hospital_Departments(hospital_name, number_of_doctors)
	{
		this->nr_of_patients = nr_of_patients;
	}
	virtual bool is_efficient() override;
	virtual string toString() override;

};
