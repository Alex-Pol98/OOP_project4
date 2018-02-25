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
	vector<Spell> spell_list;    //The list of the spells of the hero
	vector<Weapon> weapon_list;  //The list of the weapons of the hero
 	vector<Armor> armor_list;    //The list of the armors of the hero
	vector<Potion> potion_list;  //The list of the potions of the hero

public:
	Inventory() { ; }

	//Adds an item
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

	int get_spell_list_size();
	int get_weapon_list_size();
	int get_armor_list_size();
	int get_potion_list_size();

	bool is_spell_list_empty();
	bool is_armor_list_empty();
	bool is_weapon_list_empty();
	bool is_potion_list_empty();

	string get_potion_type(int i);
	int get_potion_power(int i);

	int get_spell_manareq(int i);
	int get_spell_damage(int i);
	string get_spell_type(int i);

	//Returns the price of the i_th item
	int get_spell_price(int i);   
	int get_weapon_price(int i);
	int get_potion_price(int i);
	int get_armor_price(int i);
};

#endif //INVENTORY
