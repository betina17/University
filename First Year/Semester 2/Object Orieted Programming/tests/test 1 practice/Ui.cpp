#include "UI.h"
#include <string>
#include <iostream>

/*UserInterface::UserInterface()
{
	services = Services();
}*/
//nu mai fac asta pt ca am apelat deja constructoru gol pt services in header. la repo fac pt ca acolo apelez gol in services.h si 
//in servies.cpp fac cu constructor(100)
void UserInterface::generate_5_random_cars()
{
	Car car1 = Car("Fiat", "Bravo", "red", 2007);
	services.add_service(car1);
	Car car2 = Car("Fiat", "Idea", "blue", 2003);
	services.add_service(car2);
	Car car3 = Car("Audi", "A5", "blue", 2007);
	services.add_service(car3);
	Car car4 = Car("BMW", "Coupe", "pink", 2013);
	services.add_service(car4);
	Car car5 = Car("Ford", "Fiesta", "yellow", 1976);
	services.add_service(car5);
}
void UserInterface::start_menu()
{		
	generate_5_random_cars(); //APELEAZA FUNCTIA ASTA!!!!
	char* option = new char[10];
	std::cout << "Write 'show' to show all cars";
	std::cout << "\nWrite 'add' to add a new car";
	std::cout << "\nWrite 'remove' to remove a car";
	std::cout << "\nWrite 'sort' to sort all cars by manufacturer and model and display them";
	std::cout << "\nWrite 'exit' to exit the program";
	
	while (1)
	{
		std::cout << "\nIntroduce your option>";
		std::cin >> option;
		//PUNE IN INTERIOR LOOP
		if (strcmp(option, "show") == 0)
			for (int i = 0; i < get_services().get_repo().get_size(); i++)
			{
				std::cout << get_services().get_repo().get_element(i).display_as_string();
				std::cout << "\n";
			}	//LA APELUL FUNCTIEI DISPLAY MEREU DA COUT, ALTFEL NU ITI AFISEAZA NIMIC!!!!
		else if (strcmp(option, "add") == 0)
		{
			std::string manufacturer, model, colour;
			int year_of_fabrication;
			std::cout << "\nmanufacturer>";
			std::cin >> manufacturer;
			std::cout << "\nmodel>";
			std::cin >> model;
			std::cout << "\ncolour>";
			std::cin >> colour;
			std::cout << "\nyear of fabrication>";
			std::cin >> year_of_fabrication;
			Car new_car = Car(manufacturer, model, colour, year_of_fabrication);
			services.add_service(new_car);
		}
		else if (strcmp(option, "exit") == 0)
			break;

	}
	delete[] option;
	
}