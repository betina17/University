#pragma once
#include "Domain.h"

typedef struct
{
    Medicine* elems;
    //structura contine elemente care sunt pointeri spre obiecte de tip Medicine
    int length;
    int capacity;

}DynamicArray;  ///Repository ul meu e de tip DynamicArray, cum in pyhton era o lista de exemplu unde stocam datele, si pe langa lista aia, in repo mai aveam declarate poate
///si alte chestii, cum aici avem length si capacity. Deci eu o sa am un array dinamic care va reprezenta repo-ul, iar in repo, adica in acest array, voi stoca toate
///obiectele mele de tip Medicine, Medicine fiind domeniul.

DynamicArray* createDynamicArray(int capacity);

void destroyDynamicArray(DynamicArray* array);
void resizeDynamicArray(DynamicArray* array);
void add(DynamicArray* array, Medicine* elem);
int removeMedicine(DynamicArray* array, int position);
int update(DynamicArray* array, int position_to_update, int new_price, int new_quantity);
int getLength(DynamicArray* array);
int getCapacity(DynamicArray* array);
char* display_array(DynamicArray* array);
void TestDynamicArray();
DynamicArray* copy_array(DynamicArray* array);
Medicine* get_elems(DynamicArray* array);
Medicine* get_medicine(DynamicArray* array, int position);
void TestAdd();
void TestRemove();
void TestUpdate();
void TestDynamicArray();
///getterul returneaza parametrul dintr-o structura
