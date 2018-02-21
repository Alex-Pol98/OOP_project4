#include <iostream>
#include <string>
#include "Living.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

/*Living functions*/

void Living::set_health(int h) { health = h; }
int Living::get_health() { return health; }
int Living::get_level() { return lvl; }


/*Hero functions*/
void Hero::print_stats()
{
	cout << "Hero statistics:"<< endl;
	cout << "Health= " << health << endl;
	cout << "Level= " << lvl << endl;
	cout << "Magic power= " << magic_power << endl;
	cout << "Dexterity= " << dexterity << endl;
	cout << "Strength= " << strength << endl;
	cout << "Agility= " << agility << endl;
	cout << "Money= " << money << endl;
	cout << "Experience= " << experience << endl;
	cout << "Exprerience required= " << exp_req << endl;

	if (weapon != NULL)
	{
		cout << "Equiped weapon: " << weapon->get_name() << endl;
	}
	else
	{
		cout << "No equiped weapon" << endl;
	}
	if (armor != NULL)
	{
		cout << "Equiped armor: " << armor->get_name() << endl;
	}
	else
	{
		cout << "No equiped armor" << endl;
	}
}
int Hero::get_magicpower() { return magic_power; }
int Hero::get_strength() { return strength; }
int Hero::get_dexterity() { return dexterity; }
int Hero::get_agility() { return agility; }
int Hero::get_money() { return money; }
int Hero::get_experience() { return experience; }
int Hero::get_expreq() { return exp_req; }

void Hero::equip_weapon(int no)
{
	if (inv.weapon_list.size() >= no)
	{
		if (weapon == NULL)
		{
			weapon = new Weapon(inv.weapon_list[no - 1]);
			inv.remove_weapon(no);
			cout << "Weapon equipped" << endl;
		}
		else
		{
			Weapon tmp(*weapon);
			delete weapon;
			weapon = new Weapon(inv.weapon_list[no - 1]);
			inv.remove_weapon(no);
			inv.add_weapon(tmp);
			cout << "Weapon swapped" << endl;
		}
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::equip_armor(int no)
{
	if (inv.armor_list.size() >= no)
	{
		if (armor == NULL)
		{
			armor = new Armor(inv.armor_list[no - 1]);
			inv.remove_armor(no);
			cout << "Armor equiped" << endl;
		}
		else
		{
			Armor tmp(*armor);
			delete armor;
			armor = new Armor(inv.armor_list[no - 1]);
			inv.remove_armor(no);
			inv.add_armor(tmp);
			cout << "Armor swapped" << endl;
		}
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::sell_equipedweapon()
{
	money = +weapon->get_price()/2;
	delete weapon;
	weapon = NULL;
	cout << "Equiped weapon sold" << endl;
}

void Hero::sell_equipedarmor()
{
	money = +armor->get_price() / 2;
	delete armor;
	armor = NULL;
	cout << "Equiped armor sold" << endl;
}

void Hero::sell_weapon(int no)
{
	if (inv.weapon_list.size() >= no)
	{
		money = money +(inv.weapon_list[no - 1].get_price()/ 2);
		inv.remove_weapon(no);
		cout << "Weapon sold" << endl;
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::sell_armor(int no)
{
	if (inv.armor_list.size() >= no)
	{
		money = money + (inv.armor_list[no - 1].get_price() / 2);
		inv.remove_armor(no);
		cout << "Armor sold" << endl;
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::sell_potion(int no)
{
	if (inv.potion_list.size() >= no)
	{
		money = money + (inv.potion_list[no - 1].get_price() / 2);
		inv.remove_potion(no);
		cout << "Potion sold" << endl;
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::sell_spell(int no)
{
	if (inv.spell_list.size() >= no)
	{
		money = money + (inv.spell_list[no - 1].get_price() / 2);
		inv.remove_spell(no);
		cout << "Spell sold" << endl;
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}

void Hero::addMoney(int mon) { money = money + mon; }
void Hero::subMoney(int mon) { money = money - mon; }

void Hero::tossArmor()
{
	delete armor;
	armor = NULL;
}

void Hero::tossWeapon()
{
	delete weapon;
	weapon = NULL;
}

Armor* Hero::getEquippedArmor() { return this->armor; }
Weapon* Hero::getEquippedWeapon() { return this->weapon; }

/*Warrior functions*/	
void Warrior::check_levelup()
{
	if (experience >= exp_req)
	{
		experience = experience - exp_req;
		exp_req = exp_req * 1.2 + 100 *lvl;
		lvl++;
		strength = +10;
		dexterity = +5;
		agility = +7;
		health = +50;
		magic_power = +15;
	}
}

void Warrior::sub_magicpower(int value)
{
	c_magicpower = c_magicpower - value;
}

void Warrior::restore_health(int value)
{
	c_health = c_health + value;
	if (c_health > health)
	{
		c_health = health;
	}
	cout << "Health restored!" << endl;
}

void Warrior::restore_magicpower(int value)
{
	c_magicpower = c_magicpower + value;
	if (c_magicpower > magic_power)
	{
		c_magicpower = magic_power;
	}
	cout << "Magic power restored!" << endl;
}


/*Sorcerer functions*/
void Sorcerer::check_levelup()
{
	if (experience >= exp_req)
	{
		experience = experience - exp_req;
		exp_req = exp_req * 1.2 + 100 *lvl;
		lvl++;
		strength = +5;
		dexterity = +10;
		agility = +7;
		health = +30;
		magic_power = +35;
	}
}

void Sorcerer::sub_magicpower(int value)
{
	c_magicpower = c_magicpower - value;
}

void Sorcerer::restore_health(int value)
{
	c_health = c_health + value;
	if (c_health > health)
	{
		c_health = health;
	}
	cout << "Health restored!" << endl;
}

void Sorcerer::restore_magicpower(int value)
{
	c_magicpower = c_magicpower + value;
	if (c_magicpower > magic_power)
	{
		c_magicpower = magic_power;
	}
	cout << "Magic power restored!" << endl;
}


/*Paladin functions*/
void Paladin::check_levelup()
{
	if (experience >= exp_req)
	{
		experience = experience - exp_req;
		exp_req = exp_req * 1.2 + 100 *lvl;
		lvl++;
		strength = +10;
		dexterity = +7;
		agility = +5;
		health = +60;
		magic_power = +25;
	}
}

void Paladin::sub_magicpower(int value)
{
	c_magicpower = c_magicpower - value;
}

void Paladin::restore_health(int value)
{
	c_health = c_health + value;
	if (c_health > health)
	{
		c_health = health;
	}
	cout << "Health restored!" << endl;
}

void Paladin::restore_magicpower(int value)
{
	c_magicpower = c_magicpower + value;
	if (c_magicpower > magic_power)
	{
		c_magicpower = magic_power;
	}
	cout << "Magic power restored!" << endl;
}


/*Monster functions*/
int Monster::get_damage() { return damage; }
int Monster::get_defence() { return defence; }
int Monster::get_agility() { return agility; }

void Monster::set_damage(int dmg) { damage = dmg; }
void Monster::set_defence(int def) { defence = def; }	
void Monster::set_agility(int agi) { agility = agi; }
void Monster::print_stats()
{
	cout << "Monster statistics: " << endl;
	cout << "Health= " << health << endl;
	cout << "Level= " << lvl << endl;
	cout << "Damage= " << damage << endl;
	cout << "Defence= " << defence << endl;
	cout << "Agility= " << agility << endl;
}


/*Dragon functions*/
int Dragon::get_c_health() { return c_health; }
int Dragon::get_c_damage() { return c_damage; }
int Dragon::get_c_agility() { return c_agility; }
int Dragon::get_c_defence() { return c_defence; }
void Dragon::set_c_health(int h) { c_health = h; }

void Dragon::set_c_damage(int dmg) { c_damage = dmg; }
void Dragon::set_c_defence(int def) { c_defence = def; }
void Dragon::set_c_agility(int agi) { c_agility = agi; }

void Dragon::print_data()
{
	cout << "Type: Dragon__" << "Health remaining: " << c_health << "__Level: " << lvl << endl;
}

void Dragon::receive_damage(int dmg)
{
	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
		c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 /(defence*buffs.get_all_def())));
		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Dragon died!" << endl;
		}
	}
	else
	{
		cout << "Dragon evaded the attack!" << endl;
	}
}

/*Exoskeleton functions*/
int Exoskeleton::get_c_health() { return c_health; }
int Exoskeleton::get_c_damage() { return c_damage; }
int Exoskeleton::get_c_agility() { return c_agility; }
int Exoskeleton::get_c_defence() { return c_defence; }

void Exoskeleton::set_c_health(int h) { c_health = h; }
void Exoskeleton::set_c_damage(int dmg) { c_damage = dmg; }
void Exoskeleton::set_c_defence(int def) { c_defence = def; }
void Exoskeleton::set_c_agility(int agi) { c_agility = agi; }

void  Exoskeleton::print_data()
{
	cout << "Type: Exoskeleton__" << "Health remaining: " << c_health << "__Level: " << lvl << endl;
}

void Exoskeleton::receive_damage(int dmg)
{
	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
		c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 / (defence*buffs.get_all_def())));
		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Exoskeleton died!" << endl;
		}
	}
	else
	{
		cout << "Exoskeleton evaded the attack!" << endl;
	}
}



/*Spirit functions*/
int Spirit::get_c_health() { return c_health; }
int Spirit::get_c_damage() { return c_damage; }
int Spirit::get_c_agility() { return c_agility; }
int Spirit::get_c_defence() { return c_defence; }

void Spirit::set_c_health(int h) { c_health = h; }
void Spirit::set_c_damage(int dmg) { c_damage = dmg; }
void Spirit::set_c_defence(int def) { c_defence = def; }
void Spirit::set_c_agility(int agi) { c_agility = agi; }

void Spirit::print_data()
{
	cout << "Type: Spirit__" << "Health remaining: " << c_health << "__Level: " << lvl << endl;
}

void Spirit::receive_damage(int dmg)
{
	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
		c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 / (defence*buffs.get_all_def())));
		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Spirit died!" << endl;
		}
	}
	else
	{
		cout << "Spirit evaded the attack!" << endl;
	}
}
