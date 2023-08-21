#include "Observer.h"
#pragma once
#include <vector>
class Subject
{
private:
	std::vector<Observer*> observers;
	//AICI AI NEAPART NEVOIE DE POINTER. DE CE? pentru ca observerii mei vor fi window-urile. clasa window da
	//inherit de la clasa observer. window-urile sunt obiecte specifice qt, care sunt NEAPARAT POINTERI(trebe
	//alocate dinamic)- Window* new_window....pentru ca sunt pointeri, si tipu din vector tre sa fie 
	//observer*, pentru ca eu de fapt in vector bag obiecte de tip window, si daca alea sunt pointeri, tre si 
	//astea sa zici ca sunt pointeri. sunt obiecte de tip window cu referinta spre clasa Observer-
	//polimorfism. sunt Observer* new_window = new Window().... ceva gen
public:
	Subject() {};
	~Subject() {};
	void add_observer(Observer* new_observer) //atunci toate trebe sa fie Observer* pe care le bagi in vector
											//de aia e f imp sa pui steluta aici
	{
		observers.push_back(new_observer);
	}
	void erase_observer(Observer* observer_to_erase)
	{
		observers.erase(find(observers.begin(), observers.end(), observer_to_erase));
	}
	void notify()
	{
		for (Observer* observer : observers) //steluta si aici
			observer->update();

	}
};