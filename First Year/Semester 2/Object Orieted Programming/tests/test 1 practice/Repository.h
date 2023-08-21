#pragma once
#include "Domain.h"
#include <string>
class Repository
{
private:
	Car* elements;
	int size, capacity;
	void resize();
public:
	Repository();
	Repository(int capacity);
	Repository(Repository& repository);
	Repository& operator=(const Repository&);
	~Repository();
	//mereu fa copy constructor si assignement operator cand lucrezi cu memorie alocata dinamic!!
	//n-are sens sa fac functie de display in repo, merg cu un for in ui pe vector si apelez pt fiecare elem display_elem, e frumos, e ca si cum folosesc self in python in interiorul clasei
	void add_repo(Car new_car);
	int get_size() { return this->size; }
	int get_capacity() { return this->capacity; }
	Car& get_element(int position_in_repo) { return this->elements[position_in_repo]; }
};