#include <iostream>
#include <string>
#include "Inventory.h"
#include "Spell.h"
#include "Living.h"

using namespace std;

int main(void)
{
	string a;
	Inventory inv;
	Paladin pal;
	Spell sp1("Fireball", "Fire", 110, 3, 45, 20);
	Spell sp2("Iceball", "Ice", 100, 4, 40, 18);
	Spell sp3("Lightningball", "Lightning", 135, 5, 70, 30);
	Weapon wp1("Sword", 40, 1, 30, 1);
	Weapon wp2("Hammer", 75, 3, 55, 0);
	Weapon wp3("Spear", 50, 4, 35, 1);
	Armor  arm1("Steel plate", 110, 2, 15);
	Armor  arm2("Iron plate", 140, 4, 25);
	Armor  arm3("Common plate", 80, 1, 5);
	Potion pot1("Heal potion", 20, 1, "Heal", 1);
	Potion pot2("Poison", 30, 2, "Poison", 2);
	Potion pot3("Molotov", 25, 2, "Fire", 2);

	inv.add_spell(sp1);
	inv.add_spell(sp2);
	inv.add_spell(sp3);
	inv.add_weapon(wp1);
	inv.add_weapon(wp2);
	inv.add_weapon(wp3);
	inv.add_armor(arm1);
	inv.add_armor(arm2);
	inv.add_armor(arm3);
	inv.add_potion(pot1);
	inv.add_potion(pot2);
	inv.add_potion(pot3);
	inv.print_all();

	pal.equip_armor(inv, 2);
	pal.sell_armor(inv, 1);
	pal.sell_equipedarmor();
	pal.equip_armor(inv,1);
	inv.print_armors();
	cout << endl << endl;
	pal.print_stats();



	
		
	cin >> a;
	return 0;
}