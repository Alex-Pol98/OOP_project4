#ifndef INVENTORY
#define INVENTORY

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Spell.h"

using namespace std;

class Inventory
{
	friend class Hero;
protected:
	vector<Spell> spell_list;
	vector<Weapon> weapon_list;
	vector<Armor> armor_list;
	vector<Potion> potion_list;

public:
	Inventory() { ; }

	void add_spell(Spell &sp);
	void add_weapon(Weapon &weap);
	void add_armor(Armor &arm);
	void add_potion(Potion &pot);

	//Removes the n_th item
	void remove_spell(int no);  
	void remove_weapon(int no);
	void remove_armor(int no);
	void remove_potion(int no);

	Weapon get_weapon(int no);
	Armor get_armor(int no);

	void print_weapons();
	void print_armors();
	void print_spells();
	void print_potions();
	void print_all();
};

#endif //INVENTORY
