#include <iostream>
#include <vector>
#include "Market.h"
#include "Spell.h"
#include "Item.h"

using namespace std;

Market::Market(){}

/** Access spells
 * returns The current value of spells
 */
 vector<Spell> Market::getSpells() { return spells; }

/** Access m_weapons
 * returns The current value of weapons
 */
 vector<Weapon> Market::getWeapons() { return weapons; }

/** Access m_armors
 * returns The current value of armors
 */
 vector<Armor> Market::getArmors() { return armors; }

/** Access m_potions
 * returns The current value of potions
 */
 vector<Potion> Market::getPotions() { return potions; }

 void Market::print_spells()
{
	for (unsigned int i = 0; i < spells.size(); i++)
	{
		cout << "Spell #" << i + 1 << ":" << endl;
		spells[i].print_info();
	}
}

void Market::print_weapons()
{
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		cout << "Weapon #" << i + 1 << ":" << endl;
		weapons[i].print_info();
	}
}

void Market::print_armors()
{
	for (unsigned int i = 0; i < armors.size(); i++)
	{
		cout << "Armor #" << i + 1 << ":" << endl;
		armors[i].print_info();
	}
}

void Market::print_potions()
{
	for (unsigned int i = 0; i < potions.size(); i++)
	{
		cout << "Potion #" << i + 1 << ":" << endl;
		potions[i].print_info();
	}
}

void Market::print_all()
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

