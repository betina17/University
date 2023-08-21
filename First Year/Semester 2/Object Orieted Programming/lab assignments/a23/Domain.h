#pragma once
typedef struct
{
    char* name;
    int concentration;
    int quantity;
    int price;
}Medicine;

Medicine* createMedicine(char* name, int concentration, int quantity, int price);
void destroyMedicine(Medicine* medicine);
char* getName(Medicine* medicine);
int getConcentration(Medicine medicine);
int get_quantity(Medicine* medicine);
int get_price(Medicine* medicine);
void setQuantity(Medicine* medicine, int new_quantity);
void setPrice(Medicine* medicine, int new_price);
char* toString(Medicine* medicine);

///vreau sa fac o functie care sa imi printeze toate elem din dynamic array, adica din repo, adica tot repo-ul, so functia va primi ca parametru repo-ul, deci fac functia
///in repo. daca te uiti, toate fct din domain au ca parametru medicine, cum toate fct din repo au ca parametru array ul, care e repo ul
