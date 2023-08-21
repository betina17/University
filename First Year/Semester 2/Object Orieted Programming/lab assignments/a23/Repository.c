#include "Repository.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* array = malloc(sizeof(DynamicArray));
    if (array == NULL)
        return NULL;
    array->capacity = capacity;
    array->length = 0;
    array->elems = malloc(capacity * sizeof(Medicine));
    if (array->elems == NULL)
        return NULL;
    return array;
}
void destroyDynamicArray(DynamicArray* array)
{
    if (array == NULL)
        return;
    //free the space allocated for the medicines
    free(array->elems);
    array->elems = NULL; //why do we have to do this too?
    //free the space allocated for the dynaamic array
    free(array);
    //array = NULL;? do I have to do this or not?
}

void resizeDynamicArray(DynamicArray* array)
{
    if (array == NULL)
        return; //it's like return NULL :))

    array->capacity *= 2;
    Medicine* aux = realloc(array->elems, array->capacity * sizeof(Medicine));
    //aux e de tip Medicine, cum e si elems(vezi in Repository.h).
    //pui sizeof(tipu de data declarat, aux ocupa atata spatiu cata capacitate are
    //adica cate medicamente)
    //inmultita cu pe cat se intinde fiecare element dinasta, dimensiune data de tipul
    //elementului, in cazul nostru tipul fiind Medicine, deci dimensiunea e egala
    //cu dimensiunea structurii Medicine, atata ocupa un element din array
    //si din aux la fel

    if (aux == NULL)
        return;
    //mereu fa verificarile astea!

    array->elems = aux;


}
void add(DynamicArray* array, Medicine* elem) {   ///aici adaug elem in repo
    //elem e un pointer spre un obiect de tip Medicine, adica spre o structura care are campurile structurii Medicine
    if (getLength(array) == array->capacity)
        resizeDynamicArray(array);

    array->elems[array->length] = *elem;
    array->length += 1;
    free(elem);
}

    //deci array e un pointer spre o structura de date de tip DynamicArray, care contine elemente de tip Medicine,
    //adica array va avea campurile pe care le are si DynamicArray, si elementele din  array vor fi de tip MEedicine. faptul ca am folosit
    //DynamicArray* createDYnamicArray(int capacity) si cu pointer, e pt ca functia returneaza un pointer spre un obiect de tip DynamicArray
    //adica spre o structura care are aceleasi campuri ca si DynamicArray, doar ca alta fata de DynamicArray, una de sine statoare, si cu nume propriu
    //cum aici numele ei e array
    //acest array e o structura care are campurile structurii DynamicArray, adica capacity, length si ELEMENTE de tip Medicine.
    //fiind de tip Medicine, inseamna ca fiecare element din acesta e o structura care are campurile structurii Medicine. na, aceste elemente sunt
    //puse intr-un vector alocat dinamic, pe care il alocam atunci cand cream o structura de date de tip DynamicArray, cum am creat aici array, prin
    //functia DynamicArray* createDynamicArray(int capacity) din Repository.c. in acest vector, adaugam un element nou, prin aceasta functie add,
    //in care suntem acu, element de tip Medicine, pe care il cream prin functia
    //Medicine* createMedicine(char* name, int concentration, int quantity, int price) din Domain.c
    //aceste elemente sunt alocate dinamic, intr-un vector alocat dinamic, pt care se aloca capacity*sizeof(Medicine)-pt ca elementele sunt de tip Medicine-
    //in memorie.
    //daca vectorul alocat dinamic pt aceste elemente nu mai are spatiu cand vrem sa adaugam un elem nou, ii crestem capacitatea, cum am fc mai sus
    //elems va fi un vector cu elemente de tip Medicine, vector alocat dinamic (in createDynamicArray, unde cream structura array, zicem array->elems =
    //capacity*sizeof(TElem), adica noi cream structura array de tip DynamicArray, si ii completam campurile-ii dam un length, o capacitate, si alocam
    //memorie pt vectorul alocat dinamic din acea structura, vector cu elemente de tip Medicine, prin array->elems=capacity*sizeof(Medicine))
    //array->elems e ca si cum zicem self.__elems in python. dif e ca in python, am fi declarat in constructor, adica in
    //__init__ self.__elems = [], dar aici nu facem asta pt ca alocam dinamic, si in python nu trb sa precizezi tipul de data, gen int v = []
    //sau char v = [], cum trebuia sa precizezi in c++, si inclusiv aici, unde ai zis in structura DynamicArray ca elems sunt de tip Medicine, adica
    //ca tu in vectorul elems o sa ai elemente de tip TElem, nu de tip int sau de tip char
    //cum mi-a fost greu sa inteleg conceptul de clase, obiecte, inheritence, constructor bla bla in python, dar am facut-o pana la urma, asa o sa
    //inteleg si pointerii in c


int removeMedicine(DynamicArray* array, int i)
{       int has_been_removed = 0;
    for (int med = i;med< getLength(array); med++)
    {
        array->elems[med] = array->elems[med+1];
        has_been_removed = 1;
    }
    array->length-=1;
    return has_been_removed;
}

int update(DynamicArray* array, int position_to_update, int new_price, int new_quantity)
{
    setPrice(get_medicine(array, position_to_update), new_price);
    setQuantity(get_medicine(array, position_to_update), new_quantity);
    return 1;
}


int getLength(DynamicArray* array)
{
    return array->length;
}

int getCapacity(DynamicArray* array)
{
    return array->capacity;
}

Medicine* getAll(DynamicArray* array) ////ca la orice parametru din antetul fucntiei, trb sa precizezi tipul, iar tipul structurii pe care
////vrei sa o afisezi e DynamicArray, iar din ea sa afisezi vectorul alocat dinamic array->elems
////ca asta contine toate elem din structura array, elementele fiind de tip Medicine
{
    return array->elems;
}

char* display_array(DynamicArray* array)
{   int length_of_array = getLength(array);
    if(length_of_array == 0)
        printf("There are no medicines");
    for(int i=0; i<length_of_array;i++)
        printf("%s",toString(&array->elems[i]));

}

void TestDynamicArray()
{
    DynamicArray* array = createDynamicArray(1);
    if (array == NULL)
        assert(0);

    assert(getCapacity(array) == 1);
    assert(getLength(array) == 0);

    Medicine* medicine1 = createMedicine("Algocalmin", 500, 3, 25);
    //pui Medicine pt ca medicine1 e elem de tip Medicine, cum ai pune int sau char
    add(array, medicine1);
    assert(getLength(array) == 1);

    Medicine* medicine2 = createMedicine("Paracetamol", 1000, 5, 30);
    add(array, medicine2);
    assert(getLength(array) == 2);
    assert(getCapacity(array) == 2); //capacity must pe double, adica 2*1

    destroyDynamicArray(array);
}
void TestAdd()
{
    DynamicArray* array = createDynamicArray(1);
    Medicine* medicine1 = createMedicine("Algocalmin", 500, 3, 25);
    add(array, medicine1);
    assert(getLength(array) == 1);
    assert(getCapacity(array) == 1);
    assert(strcmp(getName(get_medicine(array, 0)), "Algocalmin") == 0);
    assert(getConcentration(*get_medicine(array, 0)) == 500);
    assert(get_quantity(get_medicine(array, 0)) == 3);
    assert(get_price(get_medicine(array, 0)) == 25);
    destroyDynamicArray(array);
}
void TestUpdate()
{
    DynamicArray* array = createDynamicArray(1);
    Medicine* medicine1 = createMedicine("Algocalmin", 500, 3, 25);
    add(array, medicine1);
    assert(getLength(array) == 1);
    assert(getCapacity(array) == 1);
    assert(strcmp(getName(get_medicine(array, 0)), "Algocalmin") == 0);
    assert(getConcentration(*get_medicine(array, 0)) == 500);
    assert(get_quantity(get_medicine(array, 0)) == 3);
    assert(get_price(get_medicine(array, 0)) == 25);
    update(array, 0, 30, 5);
    assert(get_quantity(get_medicine(array, 0)) == 5);
    assert(get_price(get_medicine(array, 0)) == 30);
    destroyDynamicArray(array);
}
void TestRemove()
{
    DynamicArray* array = createDynamicArray(1);
    Medicine* medicine1 = createMedicine("Algocalmin", 500, 3, 25);
    add(array, medicine1);
    assert(getLength(array) == 1);
    assert(getCapacity(array) == 1);
    assert(strcmp(getName(get_medicine(array, 0)), "Algocalmin") == 0);
    assert(getConcentration(*get_medicine(array, 0)) == 500);
    assert(get_quantity(get_medicine(array, 0)) == 3);
    assert(get_price(get_medicine(array, 0)) == 25);
    removeMedicine(array, 0);
    assert(getLength(array) == 0);
    destroyDynamicArray(array);
}
///la teste nu mai trebuia neap sa creez iar array-ul si sa adaug elemente, ci sa folosesc array-ul creat in main, si sa adaug elemente in el, si nici sa mai testez array-ul
///in fiecare test, pt ca deja am test pt array mai sus
DynamicArray* copy_array(DynamicArray* array)
{
    DynamicArray* copy = createDynamicArray(getLength(array));
    return copy;
}
Medicine* get_elems(DynamicArray* array)
{
    return array->elems;
}
Medicine* get_medicine(DynamicArray* array, int position)
{
    return &array->elems[position];
}
