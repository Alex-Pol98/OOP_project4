#include <iostream>
#include <string>
#include "Inventory.h"
#include "Spell.h"
#include "Living.h"
#include "Buff.h"
#include "Buff_list.h"
#include "Batlle.h"

using namespace std;

int main(void)
{
	string a;
	Hero* Heroes[3];
	Heroes[0] = new Paladin();
	Heroes[1] = new Sorcerer();
	Heroes[2] = NULL;
	Potion pt("Potion", 40, 1, "Health", 70);
	Weapon wp("Sword",110,1,20,1);
	Armor ar("Plate", 100, 1, 15);
	Spell sp("Fireball", "Fire", 100, 2, 35, 40);
	Spell sp1("Blizzard","Ice", 100, 1,30, 45);
	
	Heroes[1]->inv.add_armor(ar);
	Heroes[1]->inv.add_weapon(wp);
	Heroes[1]->equip_armor(1);
	Heroes[1]->equip_weapon(1);
	Heroes[1]->inv.add_potion(pt);
	Heroes[1]->inv.add_potion(pt);
	Heroes[1]->inv.add_spell(sp);
	Heroes[1]->inv.add_spell(sp1);

	Heroes[0]->inv.add_weapon(wp);
	Heroes[0]->inv.add_armor(ar);
	Heroes[0]->inv.add_potion(pt);
	Heroes[0]->inv.add_potion(pt);
	Heroes[0]->inv.add_potion(pt);
	Heroes[0]->inv.add_spell(sp);
	Heroes[0]->equip_armor(1);
	Heroes[0]->equip_weapon(1);

	battle_procedure(Heroes);


	cin >> a;
	return 0;
}