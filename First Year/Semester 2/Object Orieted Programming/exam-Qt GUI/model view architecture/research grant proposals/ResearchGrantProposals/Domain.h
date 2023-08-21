#pragma once
#include <string>
class Researcher
{
private:
	std::string name, position;
public:
	Researcher();
	Researcher(const std::string& name, const std::string& position);
	~Researcher() {};
	std::string& get_name()
	{
		return this->name;
	};
	std::string& get_position(){ return this->position; }
};

class Idea
{
private:
	std::string title, description, status, creator;
	//Researcher creator; //nu pun Researcher*, pt ca si cand dau alte type-uri, nu pun *. nu folosi pointeri decat 
	//atunci cand e necesar. cand aveam clase cu inheritance, gen mama fiu foloseam Base* obj = new Derived
	int duration;
public:
	Idea(const std::string& title, const std::string& description, const std::string& status, const std::string& name, int duration);
	Idea();
	std::string& get_title() { return this->title; };
	std::string& get_description() { return this->description; };
	std::string& get_status() { return this->status; };
	std::string& get_creator() { return this->creator; };
	int& get_duration() { return this->duration; }
	void set_status(std::string new_status) { status = new_status; };
	void set_description(std::string new_description) { description = new_description; };
	void set_duration(int new_duration) { duration = new_duration; };
	void set_title(std::string new_title) { title = new_title; };
	void set_creator(std::string new_creator) { creator = new_creator; };

};