#pragma once
class Observer
{
public:
	Observer() {};
	~Observer() {};
	void virtual update() = 0;
};