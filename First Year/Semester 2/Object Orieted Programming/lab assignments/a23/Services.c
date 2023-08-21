#include "Services.h"
#include <stdlib.h>
#include <string.h>
Service* createService(DynamicArray* repository)
{
    Service* service =  malloc(sizeof(Service));
    if(repository == NULL)
        return NULL;
    service->Repository = repository;
    return service;
}
///repository e un array de tip DynamicArray, il stochez in Services. asta e ca in python cand in constructorul de la services
/// transmiteam ca parametru repository-ul si ziceam ca self.__repo = repository, doar ca sa pot folosi fct din repository. asa si aici, le conectez, vreau sa ma folosesc
///de fct din repository, adica functiile pe care le aplic pe dynamicarray, ca acest repo e un dyynamicarray, care dynamicarray si el foloseste fct de la elem din el, adica din
///domeniu, adica functiile asociate obiectelor de tip Medicine

void destroyService(Service* service)
{   free(service->Repository);
    free(service);
}
///si la destroyDynamicarray, adica la destroyRepo am distrus prima oara campul principal din structura DynamicArray, adica din Repo, el fiind array->elems
/// (free (array->elems)), si apoi am distrus repo ul in sine, adica dynamic array-ul (free(array)). asa si acum, prima oara distrugem chestia cu care comunica Service-ul,
///campul lui principal, Repository ul, si apoi structura Service in sine
///dam free la fiecare particica alocata dinamic din structura, asa cum in Domain.c am dat free la medicine->name, la celalalte 3 campuri nu a mai fost nevoie sa dam free
///ca nu au fost alocate dinamic, si apoi am dat free la toata structura(free->medicine), basically am sters si adresa de la inceputul structurii. despre asta e vorba, despre
///a da free la ce campuri sunt alocate dinamic
int searchMedicineInArray(DynamicArray* array, char*name, int concentration)
{   int medicine_exists = -1;
    for(int i=0;i< getLength(array);i++)
    {
        if(strcmp(getName(&array->elems[i]), name)==0 && getConcentration(array->elems[i]) == concentration ) {
            medicine_exists = i;
            break;
        }

    }
    return medicine_exists;
}
void addMedicineService(DynamicArray* array, char* name, int concentration, int quantity , int price)
{   //aici creez medicamentul
    Medicine* new_medicine = createMedicine(name, concentration, quantity, price);
    add(array, new_medicine);
}

DynamicArray* create_array_of_elements_containing_string( DynamicArray* array, DynamicArray* valid_array, char* string)
{
    int position = 0;
    for(int i=0;i<getLength(array);i++) {
        if (strstr(getName(&array->elems[i]), string) != NULL)
        {valid_array->elems[position] = array->elems[i];
            valid_array->length++;
            position++;}

    }
    return valid_array;
}
DynamicArray* sort_array_by_name(DynamicArray* array)  ///unde nu am nevoie de "self", in cazul asta de Service* service
{
    int length = getLength(array); ///array structura are lungie, nu array-elems
    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(strcmp(getName(&array->elems[i]), getName(&array->elems[j]))>0)
            {
                Medicine aux = array->elems[i];
                array->elems[i] = array->elems[j];
                array->elems[j] = aux;
            }
        }
    }
    return array;
}
DynamicArray* get_repository(Service* service)
{
    return service->Repository;
}