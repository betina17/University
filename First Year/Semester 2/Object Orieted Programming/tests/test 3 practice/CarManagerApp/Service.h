#include "CarRepository.h"
#include <algorithm>
#pragma once
class Service
{
private:
	CarRepository CarRepo;
public:
	void sort_cars_by_manufacturer();
	CarRepository& get_car_repo();
	//TREBUIE NEAPARAT SA PUN REFERINTA LA GETTERII ELEMENTELOR PE CARE LE MODIFIC PE PARCURSUL PROGRAMULUI, CA DACA NU, GETTERUL MEU RETURNEAZA O COPIE A 
	//ACELUI ELEMENT, IN CAZUL ASTA, A VECTORULUI CARS
	//service.get_car_repo().read_from_file(); eu aici, in carManagerApp.cpp apelez functia de citire din fisier ca sa citeasca in vector, si in interiorul
	//functiei baga bine in vector, si size e 5, dar get_car_repo() nu returna referinta inainte, ci returna o copie a vectorlui car, iar copia o returna
	//inainte de read_from_file, si deci, returna vectorul gol, ca asa era el inainte de read_from_file si asa s-a facut si copia. nu puteam scrie
	//am scris service.get_car_repo().read_from_file() ca sa pot accesa read_form_file din interiorul clasei CarRepository. DEci, cel mai bine returnez 
	//referinta la getteri si lucrez mereu cu originalul

};