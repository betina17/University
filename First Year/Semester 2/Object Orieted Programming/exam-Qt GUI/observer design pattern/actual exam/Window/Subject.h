#pragma once
#include "Observer.h"

class Subject
{
	
private:
	std::vector<Observer*> observers;
public:
	Subject() {};
	~Subject() {};
	void add_observer(Observer* observer)
	{
		observers.push_back(observer);
	}
	void remove_observer(Observer* observer)
	{
		observers.erase(find(observers.begin(), observers.end(), observer));
	}
	void notify()
	{
		for (Observer* observer : observers)
			observer->update();

	}
};