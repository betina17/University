#pragma once
#include <string>
class Department
{
private:
	std::string name, description;
public:
	Department() {};
	Department(std::string name1="" , std::string description1="") : name(name1), description(description1) {};
	//constructor neinitializat+initializat 2 in 1. daca nu dau parametru de nume si dau doar descriere, descrierea
	//va lua val lui description1 iar nume va lua val lui "", si nu mai tre sa fac onstructor neinitializat separat
	~Department() {};
	std::string& get_name() { return name; };
	std::string& get_description() { return description; };
};

class Volunteer
{
private:
	std::string name, email, list_of_interests, department;
public:
	Volunteer() {};
	Volunteer(std::string name1="" , std::string email1="", std::string list_of_interests1="", std::string department1="") :
		name(name1), email(email1), list_of_interests(list_of_interests1), department(department1) {};
	~Volunteer() {};
	std::string& get_name() { return name; };
	std::string& get_email() { return email; };
	std::string& get_list_of_interests() { return list_of_interests; };
	std::string& get_department() { return department; };
	
};