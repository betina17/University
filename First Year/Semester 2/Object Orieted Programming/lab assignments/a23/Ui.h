#include "Services.h"
typedef struct
{
    Service* service;

}UserInterface;

UserInterface* createUserInterface(Service* service);
void destroyUserInterface(UserInterface* userInterface);
void menu(UserInterface* userInterface);
Service* get_service(UserInterface* userInterface);
void generate_10_random_medicines(UserInterface* userInterface);
///de ce nu imi vede asta pe github desktop