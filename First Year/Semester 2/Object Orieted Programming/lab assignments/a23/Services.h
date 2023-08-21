#pragma once
#include "Repository.h"

typedef struct
{
    DynamicArray* Repository;
}Service;

Service* createService(DynamicArray* repository);
void destroyService(Service* service);
void addMedicineService(DynamicArray* array, char* name, int concentration, int quantity , int price); ///??? daca pun si numele parametrului aici, orientativ, ca sa ma ajute
///pe mine, presupun ca am voie sa il schimb atunci cand apelez functia nu? chiar daca tipul de mai am voie sa il schimb?????DAAAAA
DynamicArray* create_array_of_elements_containing_string(DynamicArray* array, DynamicArray* valid_array, char* string);
DynamicArray* sort_array_by_name(DynamicArray* array);
DynamicArray* get_repository(Service* service);
int searchMedicineInArray(DynamicArray* array, char*name, int concentration);


////asa cum in structura DynamicArray ai TEelem* elems, adica poti avea mai multe elemente de tip TElem intr-o structura de tip
///DynamicArray, pe care le aloci dinamic intr-un vector alocat dinamic pe care il cream in functia createDynamicArray, alocand memorie in functie de capacitatea primita
///ca parametru in acea functie. La fel in structura Service, am DynamicArray* Repository, adica pot avea mai multe Repository uri de tip DynamicArray, pe care le aloc dinamic
///in functia createService(DynamicArray*), atunci cand adaug cate unul. Deci un Service poate avea mai multe Repositories de tip DynamicArray, un astfel de Repository, adica
///un DynamicArray poate avea mai multe elemente de tip TElem, in cazul nostru, de tip medicament. Eu asa inteleg, nu stiu daca e bine.NU!!!!!!!!!!
///am un singur service, un singur repo, un singur dynamicarray, si un singur domeniu, adica medicament. m am complicat cu TElem, cu mai multe array uri, pt ca am generalizat
///eu trb sa fca doar pe probl mea




