#include "UI.h"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

void User_Interface::display_shopping_basket()
{
	for (auto& trench_coat : shopping_basket)
		std::cout << trench_coat.display_as_string();
}

void User_Interface::generate_10_random_trench_coats()
{
	TrenchCoat trench1 = TrenchCoat("s", "red", 100, 10, "https://www.farfetch.com/ro/shopping/women/dolce-gabbana-belted-trench-coat-item-17566049.aspx");
	TrenchCoat trench2 = TrenchCoat("m", "blue", 110, 12, "https://answear.ro/p/lauren-ralph-lauren-trenci-femei-culoarea-albastru-marin-de-tranzitie-cu-doua-randuri-de-nasturi-764035");
	TrenchCoat trench3 = TrenchCoat("m", "green", 120, 8, "https://www.fashiondays.ro/p/trenci-din-amestec-de-lyocell-cu-detalii-funda-martna-femei-ted-baker-p5349737-1/");
	TrenchCoat trench4 = TrenchCoat("l", "black", 130, 6, "https://www.zalando.ro/mango-trenci-black-m9121u19y-q11.html");
	TrenchCoat trench5 = TrenchCoat("s", "brown", 140, 15,"https://www2.hm.com/ro_ro/productpage.1115457004.html");
	TrenchCoat trench6 = TrenchCoat("m", "gray", 150, 5, "https://www.farfetch.com/ro/shopping/women/anine-bing-finley-water-repellent-double-breasted-trench-coat-item-19672603.aspx");
	TrenchCoat trench7 = TrenchCoat("s", "white", 160, 9, "https://ro.maxmara.com/p-9021053706002-atrench-ecru");
	TrenchCoat trench8 = TrenchCoat("m", "yellow", 170, 7,"https://ro.maxmara.com/p-5021023706017-lembi-yellow");
	TrenchCoat trench9 = TrenchCoat("l", "pink", 180, 4, "https://modivo.ro/p/boss-trench-cacargo-50472139-violet-regular-fit");
	TrenchCoat trench10 = TrenchCoat("l", "purple", 190, 11, "https://www.cettire.com/ro/products/msgm-belted-waist-double-breasted-coat-919558525/cmVhY3Rpb24vcHJvZHVjdDpaYjd2NzZiaTd4dmpxaTMzZA%3D%3D");
	data_base.push_back(trench1);
	data_base.push_back(trench2);
	data_base.push_back(trench3);
	data_base.push_back(trench4);
	data_base.push_back(trench5);
	data_base.push_back(trench6);
	data_base.push_back(trench7);
	data_base.push_back(trench8);
	data_base.push_back(trench9);
	data_base.push_back(trench10);


}
//poti prescurta linkurile taindu-le de la primul semn de intrebare incolo, tai inclusiv semnul
void User_Interface::start_menu()
{
	char person;
	generate_10_random_trench_coats();
	int position_of_trench_coat_in_repo;
	while(1)
	{
		std::cout << "For admin mode, press a\n";
		std::cout <<"For user mode, press b\n";
		std::cout << "To exit the store, press c\n";
		std::cout << "Intrduce your option>";
		std::cin >> person;
		if (person == 'a')
		{
			int admin_option;
			while (1) {
				std::cout << "\nPress 1 to display all the trench coats available in the store\n";
				std::cout << "Press 2 to add a trench to the database\n";
				std::cout << "Press 3 to remove a trench from the database, if it is out of supply\n";
				std::cout << "Press 4 to update the information about a trench coat\n";
				std::cout << "Press 5 to exit administrator mode\n";
				std::cout << "Introduce your administrator option>";
				std::cin >> admin_option;
				if (admin_option == 1)
				{
					for (auto& trench_coat : data_base)
						std::cout << trench_coat.display_as_string();
				}
				else if(admin_option == 2 || admin_option == 3 || admin_option == 4)
				{
					std::cout << "\nIntroduce the size of the trench coat>";
					std::string size;
					std::cin >> size;
					std::cout << "\nIntroduce the colour of the trench coat>";
					std::string colour;
					std::cin >> colour;
					
					auto trench_coat_iterator = std::find_if(data_base.begin(), data_base.end(), [&](TrenchCoat& trench_coat) {return trench_coat.get_colour() == colour && trench_coat.get_size() == size; });
					if(trench_coat_iterator != data_base.end())
					{	
						position_of_trench_coat_in_repo = std::distance(data_base.begin(), trench_coat_iterator);
						std::cout<<position_of_trench_coat_in_repo;
					}
	
					if (admin_option == 2)
					{
						if (trench_coat_iterator != data_base.end()) //daca iteratorul ajunge la final inseamna ca nu exista elementul respectiv deja
						{
							int quantity_of_trench_coat = data_base[position_of_trench_coat_in_repo].get_quantity();
							quantity_of_trench_coat++;
							data_base[position_of_trench_coat_in_repo].set_quantity(quantity_of_trench_coat);
							std::cout << "\nThe trench coat already exists in the database, therefore its quantity was increased\n";
						}
						else {
							std::cout << "\nIntroduce the price of the new trench coat>";
							int price;
							std::cin >> price;
							std::cout << "\nIntroduce the quantity of the new trench coat>";
							int quantity;
							std::cin >> quantity;
							std::cout << "\nIntroduce the photo of the new trench coat>";
							std::string photo_link;
							std::cin >> photo_link;
							TrenchCoat new_trench_coat = TrenchCoat(size, colour, price, quantity, photo_link);
							data_base.push_back(new_trench_coat);
						}

					}
					else if (admin_option == 3)
					{
						if (data_base.size() == 0)
							std::cout << "\nThe data base is empty, so therefore, there is no element that you can remove.\n";
						else
						{
							if (trench_coat_iterator == data_base.end())
								std::cout << "\nThis trench coat doesn't exist in our data base.\n";
							else
								data_base.erase(trench_coat_iterator);
						}
					}
					else if (admin_option == 4)
					{
						if (data_base.size() == 0)
							std::cout << "\nThe data base is empty, so therefore, there is no element that you can update.\n";
						else {

							if (trench_coat_iterator == data_base.end())
								std::cout << "\nThis trench coat doesn't exist in our data base.\n";
							else
							{
								char option_to_update = 'e';
								while (1)
								{
									std::cout << "\nTo update the price of the trench coat, press a";
									std::cout << "\nTo update the quantity of the trench coat, press b";
									std::cout << "\nTo update the photograph of the trench coat, press c";
									std::cout << "\nWhen you finished updateing the information about the trench coat, press d";
									std::cout << "\n>";
									std::cin >> option_to_update;
									if (option_to_update == 'a')
									{
										std::cout << "\nIntroduce the new price of the trench coat>";
										int new_price;
										std::cin >> new_price;
										data_base[position_of_trench_coat_in_repo].set_price(new_price);
										//nu pot sa folosesc dynamic_array.get_element(position).set_price, pt ca get_element nu returneaza
										//elementul in sine, ci o copie a lui, pt ca daca te uiti in functie elementul nu e transmir prin
										//referinta, asta inseamna ca functia returneaza o copie a elementului, si eu chiar daca schimb pretul
										//la acea copie, nu se schimba si la elementul original. PFOAAAAA.
										//daca scriam in repo Telem& get_element(int position) cu &, returna elemu, si puteam sa folosesc aici
										//dynamic_array.get_element(position_of_trench_coat_in_repo).set_price(new_price);

									}
									else if (option_to_update == 'b')
									{
										std::cout << "\nIntroduce the new quantity of the trench coat>";
										int new_quantity;
										std::cin >> new_quantity;
										data_base[position_of_trench_coat_in_repo].set_quantity(new_quantity);
									}
									else if (option_to_update == 'c')
									{
										std::cout << "\nIntroduce the new photo of the trench coat>";
										std::string new_photo_link;
										std::cin >> new_photo_link;
										data_base[position_of_trench_coat_in_repo].set_photograph(new_photo_link);
									}
									else if (option_to_update == 'd')
										break;
									else
										std::cout << "\nInvalid option.";
								}

							}
						}

					}
				}
				else if (admin_option == 5)
				{
					break;
				}
				else
					std::cout << "\nInvalid option.";
			}
		}
		else if (person == 'b')
		{
			int user_option;
			int total_price = 0;
			while (1)
			{
				std::cout << "\nPress 1 to display all the trench coats of the size you want";
				std::cout << "\nPress 2 to see display the shopping basket and the total price of your order";
				std::cout << "\nPress 3 to exit user mode";
				std::cout << "\nIntroduce your option>";
				std::cin >> user_option;
				if (user_option == 1)
				{
					std::string size;
					std::cout << "\nIntroduce the size of the trench coat>";
					std::cin >> size;
					int i = 0;
					char option = 'i';
					while (option != 'e')
						if (strcmp(data_base[i].get_size().c_str(), size.c_str()) == 0)
						{
							std::cout<<data_base[i].display_as_string();
							std::cout << "\n Press 'i' to display the link of the image of the trench coat, or press '-' to skip this step";
							std::cout <<"\n>";
							char image;
							std::cin >> image;
							if (image == 'i')
								data_base[i].ShowImage();
							else if (image == '-')
								std::cout << "\n";
							//separately or in the same call show image of the coat
							std::cout << "\n Press '+' to add the trench coat to the shooping basket, or press '-' to skip this step";
							std::cout << "\n>";
							char add;
							std::cin >> add;
							if (add == '+')
							{
								shopping_basket.push_back(data_base[i]);
								total_price = total_price + data_base[i].get_price();
							}
							if (add == '-' || add == '+')
							{
								std::cout << "\n Press'>' to go to the next trench coat, or 'e' to exit the trench coats";
								std::cout << "\n>";
								std::cin >> option;
								i++;
								if (i == (data_base.size() + 1))
									i = 0;
							}
							else
							{
								std::cout << "\nInvalid option";
								continue;
							}

						}
						else
						{
							i++;
							if (i == (data_base.size() + 1))
								i = 0;
						}

				}
				else if (user_option == 2)
				{
					std::cout << "\nYour shopping basket contains the following trench coats:\n";
					display_shopping_basket();
					std::cout << "\nThe total cost of yout shopping basket is:";
					std::cout << total_price;
					std::cout << "\n";

				}
				else if (user_option == 3)
				{
					break;
				}
			}
		}

		else if (person == 'c')
		{
			std::cout << "Thank you for your time in our store, have a great day!";
			break;
		}
		else
			std::cout << "\nInvalid option!";
		
	}
}


