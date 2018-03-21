#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Inventory.h"

using namespace std;


void Inventory::add_spell(Spell &sp) { spell_list.push_back(sp); }          // Functions to add Items in the Inventory through the push_back of
void Inventory::add_weapon(Weapon &weap) { weapon_list.push_back(weap); }   // vectors
void Inventory::add_armor(Armor &arm) { armor_list.push_back(arm); }
void Inventory::add_potion(Potion &pot) { potion_list.push_back(pot); }

void Inventory::remove_spell(int no)                        // the remove_<item> Functions checks if the number given is valid and deletes
{                                                           // the <item> from the inventory through erase of vectors
	if (spell_list.size()  < no )
	{
		cout << "Cannot delete spell" << endl;
	}
	else
	{
		spell_list.erase(spell_list.begin() + no - 1);
		//cout << "Spell erased" << endl;
	}
}
void Inventory::remove_weapon(int no)
{
	if (weapon_list.size() < no )
	{
		cout << "Cannot delete Weapon" << endl;
	}
	else
	{

		weapon_list.erase(weapon_list.begin() + no - 1);
		//cout << "Weapon erased" << endl;
	}
}
void Inventory::remove_armor(int no)
{
	if (armor_list.size()  < no  )
	{
		cout << "Cannot delete Armor" << endl;
	}
	else
	{
		armor_list.erase(armor_list.begin() + no - 1);
		//cout << "Armor erased" << endl;
	}
}
void Inventory::remove_potion(int no)
{
	if (potion_list.size() < no  )
	{
		cout << "Cannot delete Potion" << endl;
	}
	else
	{
		potion_list.erase(potion_list.begin() + no - 1);
		//cout << "Potion erased" << endl;
	}
}

Weapon Inventory::get_weapon(int no)                            // Getters for weapon and armor that returns the chosen <item> after checking
{                                                               // if the number is valid
    if (weapon_list.size() >= no)
	{
		return weapon_list[no - 1];
	}
	else
	{
			cout << "ERROR OUT OF BOUNDS WEAPON_LIST" << endl;
			assert(0);
	}
}

Armor Inventory::get_armor(int no)
{
	if (armor_list.size() >= no)
	{
		return armor_list[no - 1];
	}
	else
	{
		cout << "ERROR OUT OF BOUNDS ARMOR_LIST" << endl;
		assert(0);
	}
}


void Inventory::print_spells()                                      // print Functions for each <item> that prints every <item>'s info
{                                                                   // through print_info after checking if there are any <items>, and
	if(spell_list.size() == 0)                                      // a print_all functions that calls the others
    {
        cout << "There are no Spells available" << endl;
        return;
    }
	for (unsigned i = 0; i < spell_list.size(); i++)
	{
		cout << "Spell #" << i + 1 << ":" << endl;
		spell_list[i].print_info();
	}
}

void Inventory::print_weapons()
{
    if(weapon_list.size() == 0)
    {
        cout << "There are no Weapons available" << endl;
        return;
    }
	for (unsigned i = 0; i < weapon_list.size(); i++)
	{
		cout << "Weapon #" << i + 1 << ":" << endl;
		weapon_list[i].print_info();
	}
}

void Inventory::print_armors()
{
	if(armor_list.size() == 0)
    {
        cout << "There are no Armors available" << endl;
        return;
    }
	for (unsigned i = 0; i < armor_list.size(); i++)
	{
		cout << "Armor #" << i + 1 << ":" << endl;
		armor_list[i].print_info();
	}
}

void Inventory::print_potions()
{
	if(potion_list.size() == 0)
    {
        cout << "There are no Potions available" << endl;
        return;
    }
	for (unsigned i = 0; i < potion_list.size(); i++)
	{
		cout << "Potion #" << i + 1 << ":" << endl;
		potion_list[i].print_info();
	}
}

void Inventory::print_all()
{
	cout << "SPELLS:" << endl << endl;
	print_spells();
	cout << "_____________________________________________" << endl;
	cout << "WEAPONS:" << endl << endl;
	print_weapons();
	cout << "_____________________________________________" << endl;
	cout << "ARMORS:" << endl << endl;
	print_armors();
	cout << "_____________________________________________" << endl;
	cout << "POTIONS:" << endl << endl;
	print_potions();
	cout << "_____________________________________________" << endl;
}

bool Inventory::is_spell_list_empty() { return spell_list.empty(); }    // Functions that check if the vectors are empty

bool Inventory::is_armor_list_empty() { return armor_list.empty(); }

bool Inventory::is_weapon_list_empty() { return weapon_list.empty(); }

bool Inventory::is_potion_list_empty() { return potion_list.empty(); }

int Inventory::get_spell_list_size() { return spell_list.size(); }      // Functions that return the vectors size

int Inventory::get_weapon_list_size() { return weapon_list.size(); }

int Inventory::get_armor_list_size() { return armor_list.size(); }

int Inventory::get_potion_list_size() { return potion_list.size(); }

string Inventory::get_potion_type(int i) { return potion_list[i].get_type(); }  // Functions for returning Potions' type and power
int Inventory::get_potion_power(int i) { return potion_list[i].get_power(); }

int Inventory::get_spell_manareq(int i) { return spell_list[i].get_manareq(); } // Functions for returning Spells' Mana, Damage and Type
int Inventory::get_spell_damage(int i) { return spell_list[i].get_damage(); }
string Inventory::get_spell_type(int i) { return spell_list[i].get_type(); }

int Inventory::get_spell_price(int i) { return spell_list[i].get_price(); }     // Functions for returning <Items>'s price
int Inventory::get_weapon_price(int i) { return weapon_list[i].get_price(); }
int Inventory::get_potion_price(int i) { return potion_list[i].get_price(); }
int Inventory::get_armor_price(int i) { return armor_list[i].get_price(); }
