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
	cout << "Name: " << name << endl;
	cout << "Health= " << health << endl;
	cout << "Level= " << lvl << endl;
	cout << "Magic power= " << magic_power << endl;
	cout << "Dexterity= " << dexterity << endl;
	cout << "Strength= " << strength << endl;
	cout << "Agility= " << agility << endl;
	cout << "Money= " << money << endl;
	cout << "Experience= " << experience << endl;
	cout << "Experience required= " << exp_req << endl;

	if (weapon != NULL)
	{
		cout << "Equipped weapon: " << weapon->get_name() << endl;
	}
	else
	{
		cout << "No equipped weapon" << endl;
	}
	if (armor != NULL)
	{
		cout << "Equipped armor: " << armor->get_name() << endl;
	}
	else
	{
		cout << "No equipped armor" << endl;
	}
}
string Hero::get_name() { return name; }
int Hero::get_magicpower() { return magic_power; }
int Hero::get_strength() { return strength; }
int Hero::get_dexterity() { return dexterity; }
int Hero::get_agility() { return agility; }
int Hero::get_money() { return money; }
int Hero::get_experience() { return experience; }
int Hero::get_expreq() { return exp_req; }

void Hero::equip_weapon()
{
    int option;

    inv.print_weapons();
    if(inv.weapon_list.size() == 0)
        return;

    cout << "Choose the weapon you want to equip:" << endl;
    cin >> option;

    while(option > inv.weapon_list.size() || option < 0)
    {
        cout << "Invalid Input\nPlease Choose again:" << endl;
        cin >>option;
    }

    equip_weapon(option);
}

void Hero::equip_weapon(int no)
{
	if (inv.weapon_list.size() >= no && no > 0)
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

void Hero::equip_armor()
{
    int option;

    inv.print_armors();
    if(inv.armor_list.size() == 0)
        return;

    cout << "Choose the armor you want to equip:" << endl;
    cin >> option;

    while(option > inv.armor_list.size() || option < 0)
    {
        cout << "Invalid Input\nPlease Choose again:" << endl;
        cin >>option;
    }

    equip_armor(option);
}

void Hero::equip_armor(int no)
{
	if (inv.armor_list.size() >= no && no > 0)
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

void Hero::addExperience(int value)                 // Loukas
{
    experience += value;
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
		strength += +10;
		dexterity += +5;
		agility += +7;
		health += +50;
		c_health += +50;
		magic_power = +15;
		cout << "Warrior leveled up!" << endl;
	}
}

int Warrior::get_chealth() { return c_health; }
int Warrior::get_cmagicpower() { return c_magicpower; }

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

void Warrior::receive_damage(int dmg)
{
//	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
        if(armor != NULL)
            c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 / (armor->get_def()*buffs.get_all_def())));
        else
            c_health = c_health - dmg;

		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Warrior died!" << endl;
		}
	}
	else
	{
		cout << "Warrior evaded the attack!" << endl;
	}
}

void Warrior::print_stats()
{
	cout << "\tWarrior stats:" << endl;
	Hero::print_stats();
	cout << "Current health: " << c_health << endl;
	cout << "Current magic power: " << c_magicpower << endl;
	cout << endl;
}

/*Sorcerer functions*/
void Sorcerer::check_levelup()
{
	if (experience >= exp_req)
	{
		experience = experience - exp_req;
		exp_req = exp_req * 1.2 + 100 *lvl;
		lvl++;
		strength += +5;
		dexterity += +10;
		agility += +7;
		health += +30;
		c_health += 30;
		magic_power += +35;
		cout << "Sorcerer leveled up!" << endl;
	}
}

int Sorcerer::get_chealth() { return c_health; }
int Sorcerer::get_cmagicpower() { return c_magicpower; }

void Sorcerer::receive_damage(int dmg)
{
//	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
		if(armor != NULL)
            c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 / (armor->get_def()*buffs.get_all_def())));
        else
            c_health = c_health - dmg;

		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Sorcerer died!" << endl;
		}
	}
	else
	{
		cout << "Sorcerer evaded the attack!" << endl;
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


void Sorcerer::print_stats()
{
	cout << "\tSorcerer stats:" << endl;
	Hero::print_stats();
	cout << "Current health: " << c_health << endl;
	cout << "Current magic power: " << c_magicpower << endl;
	cout << endl;
}

/*Paladin functions*/
void Paladin::check_levelup()
{
	if (experience >= exp_req)
	{
		experience = experience - exp_req;
		exp_req = exp_req * 1.2 + 100 *lvl;
		lvl++;
		strength += +10;
		dexterity += +7;
		agility += +5;
		health += +60;
		c_health += 60;
		magic_power += +25;
		cout << "Paladin leveled up!" << endl;
	}
}

void Paladin::receive_damage(int dmg)
{
//	srand(time(NULL));
	int evade;
	evade = rand() % 301;
	if (evade < (300 - (agility*buffs.get_all_agi())))
	{
        if(armor != NULL)
            c_health = c_health - (dmg*0.5 + dmg * 0.5*(10 / (armor->get_def()*buffs.get_all_def())));
        else
            c_health = c_health - dmg;

		if (c_health <= 0)
		{
			c_health = 0;
			cout << "Paladin died!" << endl;
		}
	}
	else
	{
		cout << "Paladin evaded the attack!" << endl;
	}
}

int Paladin::get_chealth() { return c_health; }
int Paladin::get_cmagicpower() { return c_magicpower; }

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


void Paladin::print_stats()
{
	cout << "\tPaladin stats:" << endl;
	Hero::print_stats();
	cout << "Current health: " << c_health << endl;
	cout << "Current magic power: " << c_magicpower << endl;
	cout << endl;
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
	cout << "\tMonster statistics: " << endl;
	cout << "Health= " << health << endl;
	cout << "Level= " << lvl << endl;
	cout << "Damage= " << damage << endl;
	cout << "Defence= " << defence << endl;
	cout << "Agility= " << agility << endl << endl;
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
//	srand(time(NULL));
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
//	srand(time(NULL));
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
//	srand(time(NULL));
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
