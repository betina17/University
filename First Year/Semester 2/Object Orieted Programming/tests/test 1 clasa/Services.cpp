#include "Services.h"
#include <string>
Services::Services()
{
	repository = Repository(100);
}
void Services::add_player_services(Player player)
{
	repository.add_player_repo(new_player);
}