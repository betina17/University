#include "Domain.h"
Researcher::Researcher()
{
	this->name = "";
	this->position = "";
}
Researcher::Researcher(const std::string& name, const std::string& position)
{
	this->name = name;
	this->position = position;
};
Idea::Idea(const std::string& title, const std::string& description, const std::string& status, const std::string& name, int duration)
{
	this->title = title;
	this->description = description;
	this->status = status;
	this->creator = name;
	this->duration = duration;
};
Idea::Idea() {
	this->title = "";
	this->description = "";
	this->status = "";
	this->creator = "";
	this->duration = duration;
}

;