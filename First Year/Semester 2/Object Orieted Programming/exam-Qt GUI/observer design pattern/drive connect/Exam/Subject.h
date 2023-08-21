#pragma once
#include "Observer.h"
#include <vector>
#include <algorithm>
class Subject
{
private:
	std::vector<Observer*> observers; //clasa subiect are vector de observeri
public:

	~Subject() {};
	Subject() {};
	void add_observer(Observer* new_observer) //daca e pointer la std vector trebe si aici
	{
		this->observers.push_back(new_observer);
	}
	void delete_observer(Observer* observer_to_remove)
	{
		this->observers.erase(find(observers.begin(), observers.end(), observer_to_remove));
	}
	void notify()
	{
		for (Observer* observer : observers)
			observer->update();
	}

};
//snake_case
//camelCase
//PascalCase