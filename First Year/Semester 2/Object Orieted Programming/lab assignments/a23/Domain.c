#include "Domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Medicine* createMedicine(char* name, int concentration, int quantity, int price)
{
    Medicine* newMedicine = malloc(sizeof(Medicine));
    newMedicine->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    //if (newMedicine->name == NULL)
    //return NULL;   ar trebui sa fac exceptii aici
    strcpy(newMedicine->name, name);
    newMedicine->concentration = concentration;
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    return newMedicine;
}

void destroyMedicine(Medicine* medicine)
{
    free(medicine->name);
    ////free(&medicine->concentration);concentration si quantity nu sunt alocati dinamic, ca nu sunt pointeri, deci nu trb sa le dau free
    ////free( (void *) medicine->quantity); free imi cere ca argument o adresa, dar quantity si concentration nu sunt pointeri,
    ////asa ca ori pun & in fata ca sa iau adresa, ori pun (void *), care daca te uiti e exact tipul de argument de care are
    ////nevoie functia free
    free(medicine);
}

char* getName(Medicine* medicine)
{
    return medicine->name;
}

int getConcentration(Medicine medicine)
{
    return medicine.concentration;
}

int get_quantity(Medicine* medicine)
{
    return medicine->quantity;
}

int get_price(Medicine* medicine)
{
    return medicine->price;
}
void setQuantity(Medicine* medicine, int new_quantity)
{
    medicine->quantity = new_quantity;
}
void setPrice(Medicine* medicine, int new_price)
{
    medicine->price = new_price;
}
char* toString(Medicine* medicine)
{
    char* str =(char*) malloc(sizeof(char)* 500);
    sprintf(str, "Medicine %s has a concentration of %d mg, its quantity is %d, and it comes with the price of %d euros.\n", medicine->name, medicine->concentration, medicine->quantity, medicine->price);
    return str;
}
Medicine* getMedicine(Medicine* medicine)
{
    return medicine;
}
///sa folosesc doar getteri!!!


