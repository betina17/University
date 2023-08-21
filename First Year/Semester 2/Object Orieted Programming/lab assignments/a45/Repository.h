#pragma once
#include "Domain.h"
#include <string>

template <typename Telem> 
/// Telem este template element, poate fi inlocuit cu orice tip de obiect. tu cand scrii asa spui ca, clasa DynamicArray poate istantia cu 
//constructorul ORICE tip de obiect, nu doar cu TrenchCoat, ci si cu int, sau cu char, sau cu float, sau cu orice alt tip de obiect, Telem e 
//un placeholder pentru orice tip de obiect, in loc de Telem poti sa scrii si TrenchCoat, dar e mai bine sa scrii Telem, ca sa nu te limitezi
//folosesc Telem doar in in template, doar in repo, ca asta e template, si in rest folosesc TrenchCoat,in services si etc, ca asta e obiectul meu,
// trebuie cand pomenesc
//de clasa DynamicArray sa precizez ce tip de obiect instantiaza clasa, in loc de Telem, tre sa ii zic obiectul respectiv, ca sa stie pe ce lucreaza 
//in momentul ala, ca poate sa lucreze o data pe TrenchCoat, o data pe Medicine, etc etc
//de fapt, daca chiar as avea mai multe tipuri de obiecte ar trebui sa fac cu Telem si in Services, ca sa pot sa apelez in UI cu ce tip de 
//obiect vreau eu o functie din services, nu doar cu tipul TrenchCoat  cum se intampla acum, pt ca in antetul tuturor fct din services and 
//zic ca tipul param primit e TrenchCoat. Alegerea tipului de obiect trb facuta la apelul fct, nu la declararea fct, deci in UI, nu in services,
//ca sa pot sa jonglez cu ce tip de obiect vreau sa lucrez, pe ce tip de obiect vreau sa execut functia respectiva
//at the same time, nu am nevoie de service, pt ca toate functionalitatile sunt chestii de modificare repo sau de afisare repo, care  se fac in ui
//sau repo direct. o sa am repo pt data base, si repo pt shopping list, si pt ambele o sa folosesc aceleasi functii ca de aia sunt template uri
// mai customizeaza paragrafful pana aici
//IMP:adica o sa am de doua ori dynamic array, unul pt data base si unul pt shopping list, dar ambele vor avea elem de tipul TrenchCoat, ca na, asa
//e problema asta, nu aveai neap nevoie de template pt tipul de obiect daca oricum lucrezi cu un singur tip de obiect
class DynamicArray
{
private:
	Telem* elements;
	int size;
	int capacity;
	void resize();
	public:
		DynamicArray(); ///if I write my own construstors and I don t use the default one, the compiler says 'well than you re fonna have to deal
		//with the constructors yourself, so this is why I have to write the default constructor, that being the empty constructor, the one
		//that doesn t take any parameters
		DynamicArray(int capacity);  ///constructor
		DynamicArray(const DynamicArray&); ///copy constructor
		DynamicArray& operator=(const DynamicArray&); ///assignment operator 
		//am nevoie de asta aici pt ca memorie alocata dinamic, si nu e destul copy operator. 
		~DynamicArray(); ///destructor
		void add_element(Telem element);
		void delete_element(int position);
		void update_element(Telem element);
		int get_size()const { return size; }
		int get_capacity()const { return capacity; }
		Telem get_element(int position);
		//Telem& get_element(int position); ///asa returna efectiv elementul, nu copia
		void display_all_elements_in_repo();
		int search_element_in_repo(std::string size, std::string colour);
		void update_price(int new_price, int position) { elements[position].set_price(new_price); }
		void update_quantity(int new_quantity, int position) { elements[position].set_quantity(new_quantity); }
		void update_photograph(std::string new_photograph, int position) { elements[position].set_photograph(new_photograph); }
};