#include "Subject.h"
#pragma once
#include <vector>
class Session : public Subject
{
private:
	std::vector<Volunteer> volunteers;
public:
	Session() {};
	Session(std::vector<Volunteer> volunteers1) : volunteers(volunteers1) {};
	void add_volunteer(Volunteer& new_volunteer)
	{
		volunteers.push_back(new_volunteer);
		notify();
	}
	~Session() {};
	std::vector<Volunteer>& get_session_volunteers() { return  volunteers; };
	
};