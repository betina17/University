#include "UserInterface.h"
#include <string>
#include <iostream>
void UserInterface::generate_random_players()
{
	Player player1 = Player("Nora_Mork", "NOR", "Larvick", 83);
	services.add_player_services(player1);
	Player player1 = Player("Isabelle_Gullden", "SWE", "CSM_Bucuresti", 80);
	services.add_player_services(player2);
}
void UserInterface::start_menu()
{
	generate_random_players();
	char option = 'a';
	std::cout << "To add a new player, write 'add'";
	std::cout << "\nTo show all the players, write 'show'";
	std::cout << "\nTo exit the application, write 'exit'";
	while (1)
	{
		std::cout << "\nIntroduce your option>";
		std::cin >> option;
		if (strcmp(option*, "add") == 0)
		{
			std::string name, nationality, team;
			int goals;
			std::cout << "\nName>";
			std::cin >> name;
			std::cout << "\nNationality>";
			std::cin >> nationality;
			std::cout << "\nTeam>";
			std::cin >> team;
			std::cout << "\Number of goals>"
				std::cin >> goals;
			Player new_player = Player(name, nationality, team, goals);
			std::cout << services.add_player_services(new_player);
		}
		else if (strcmp(option*, "show") == 0)
			services.get_repo().display_all();
		else if (strcmp(option*, "exit") == 0)
			break;
	}

}