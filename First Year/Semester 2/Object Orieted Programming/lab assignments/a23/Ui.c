#include "Ui.h"
#include <stdlib.h>
#include <stdio.h>

UserInterface* createUserInterface(Service* service) {
    UserInterface *userInterface = malloc(sizeof(Service));
    if (service == NULL)
        return NULL;
    userInterface->service = service;
    return userInterface;
}

void destroyUserInterface(UserInterface* userInterface)
{
    free(get_service(userInterface));
    free(userInterface);
}
Service* get_service(UserInterface* userInterface)
{
    return userInterface->service;
}
void generate_10_random_medicines(UserInterface* userInterface)
{
    const char* medicine_names[] = {"Paracetamol", "Ibuprofen", "Aspirin", "Nurofen", "Naproxen", "Diclofenac", "Cetirizine", "Loratadine", "Fexofenadine", "Diphenhydramine"};
    int concentration, quantity, price;
    //srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        concentration = (rand()%10)*1000;
        quantity = rand() % 10;
        price = rand() % 10;
        addMedicineService(get_repository(get_service(userInterface)), medicine_names[i], concentration, quantity, price);
    }
///nu trb sa dau free la nimic pt ca eu nu am alocat nimic dinamic in functia astat
}
void menu(UserInterface* userInterface) {


    generate_10_random_medicines(userInterface);
    DynamicArray *our_array = get_repository(get_service(userInterface));
    printf("Welcome to the pharmacy!\n");
    printf("These are the available medicines at the moment:\n");
    display_array(our_array);
    printf("Press 1 to add a medicine\n");
    printf("Press 2 to delete a medicine\n");
    printf("Press 3 to update a medicine\n");
    printf("Press 4 to see all available medicines containing a given string\n");
    printf("Press 5 to see all those medicines that are in short supply(quantity less than a number you introduce)\n");
    printf("Press 6 to exit the program\n");
    while (1 == 1) {
        printf("\nIntroduce the options that you want>\n");
        int option;
        scanf("%u", &option);
        if (option == 1 || option == 2 || option == 3) {
            char* name = malloc(sizeof(char));   ///TODO free la name
            int concentration, quantity, price;
            printf("Introduce the name of the medicine>\n");
            scanf("%s", name);
            printf("Introduce the concentration of the medicine>\n");
            scanf("%u", &concentration);
            int position_of_medicine = searchMedicineInArray(our_array, name, concentration);
            if (option == 1) {
                if (position_of_medicine != -1) {
                    printf("Medicine already exists, therefore its quantity will be increased\n");
                    int quantity_of_medicine = get_quantity(&get_elems(
                            our_array)[position_of_medicine]); ///&asta iti da adresa, dereferentierea e cu *, trb & pt ca get_quantity primeste medicine de tip pointer, adica primeste adresa
                    setQuantity(&get_elems(our_array)[position_of_medicine], quantity_of_medicine += 1);
                    continue;
                } else {
                    printf("Introduce the quantity of the medicine>\n");
                    scanf("%u", &quantity);
                    printf("Introduce the price of the medicine>\n");
                    scanf("%u", &price);
                    addMedicineService(our_array, name, concentration, quantity, price);
                    display_array(our_array);
                }

            } else if (option == 2 || option == 3) {

                if (getLength(our_array) == 0) {
                    printf("There are no medicines in the repository, so there's nothing to remove.\n");
                    continue;
                } else if (position_of_medicine == -1)
                    printf("Medicine doesn't exist\n");
                else {
                    if (option == 2) {
                        if (removeMedicine(our_array, position_of_medicine) == 1)
                            printf("Medicine was successfully removed\n");
                        else
                            printf("Medicine couldn't be removed\n");
                        display_array(our_array);
                    }
                    else if (option == 3) {
                        printf("Introduce the updated quantity of the medicine>\n");  ///puteam sa fac ca la 45 sa pot sa dau update doar la una din chestiile astea daca vreau
                        scanf("%u", &quantity);
                        printf("Introduce the updated price of the medicine>\n");
                        scanf("%u", &price);
                        if (update(our_array, position_of_medicine, quantity, price) ==1)
                            printf("Medicine was successfully updated\n");
                        else
                            printf("Medicine couldn't be updated\n");
                        display_array(our_array);
                    }
                }
            }
        free(name);
        } else if (option == 4) {
            if (our_array->length == 0) {
                printf("There are no medicines in the repository\n");
                continue;
            }
            printf("Introduce the string that you want to search for>\n");
            char *string = malloc(sizeof(char));
            scanf("%s", string);
            DynamicArray *array_of_elements_containing_string = copy_array(our_array);
            create_array_of_elements_containing_string(our_array, array_of_elements_containing_string, string);
            sort_array_by_name(array_of_elements_containing_string);
            display_array(array_of_elements_containing_string);
            destroyDynamicArray(array_of_elements_containing_string);

        } else if (option == 5) {
            if (getLength(our_array) == 0) {
                printf("There are no medicines in the repository, so there's nothing to show.\n");
                continue;
            } else {
                printf("Introduce the quantity>\n");
                int quantity;
                scanf("%u", &quantity);
                printf("The medicines that are in short supply are:\n");
                for (int i = 0; i < getLength(our_array); i++)
                    if (get_quantity(&get_elems(our_array)[i]) < quantity)
                        printf("%s", toString(&get_elems(our_array)[i]));

            }
        } else if (option == 6) {
            printf("Exiting the program...\n");
            destroyDynamicArray(our_array);
            break;
        } else {

            printf("Invalid option\n");
            continue;
        }

    }
}
