#pragma once
#include "Subject.h"
#include <vector>
#include "Repository.h"
class Session : public Subject
{
	
private:
	std::vector<Event> events;
	std::vector<Person> persons;
public:
	Session(Repository& repository)
	{
		this->events = repository.get_events();
		this->persons = repository.get_persons();
	};
	~Session() {
		save_to_file_events_from_session();
	};
	void add_event(Event& new_event)
	{
		events.push_back(new_event);
		notify();
	}
	
	std::vector<Event>& get_events() {
		return events;
	};
	void save_to_file_events_from_session()
	{
		std::ofstream fout("events_from_session.txt");
		for (Event& event : events)
		{
			fout << event.get_organiser() + "|" + event.get_name() + "|" + event.get_description() + "|" +
				std::to_string(event.get_location().first) + "," + std::to_string(event.get_location().second) +
				"|" + event.get_date() + "|" + "\n";
		}
		fout.close();
	};
};