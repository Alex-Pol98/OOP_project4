#include <iostream>
#include <string>
#include "Living1.h"

using namespace std;

/*Living functions*/

void Living::set_health(int h) { health = h; }


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
}

int Hero::get_magicpower() { return magic_power; }
int Hero::get_strength() { return strength; }
int Hero::get_dexterity() { return dexterity; }
int Hero::get_agility() { return agility; }
int Hero::get_money() { return money; }
int Hero::get_experience() { return experience; }
int Hero::get_expreq() { return exp_req; }



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


/*Monster functions*/
int Monster::get_damage() { return damage; }
int Monster::get_defence() { return defence; }
int Monster::get_agility() { return agility; }

void Monster::set_damage(int dmg) { damage = dmg; }
void Monster::set_defence(int def) { defence = def; }	
void Monster::set_agility(int agi) { agility = agi; }


/*Dragon functions*/
int Dragon::get_c_health() { return c_health; }
int Dragon::get_c_damage() { return c_damage; }
int Dragon::get_c_agility() { return c_agility; }
int Dragon::get_c_defence() { return c_defence; }
void Dragon::set_c_health(int h) { c_health = h; }

void Dragon::set_c_damage(int dmg) { c_damage = dmg; }
void Dragon::set_c_defence(int def) { c_defence = def; }
void Dragon::set_c_agility(int agi) { c_agility = agi; }



/*Exoskeleton functions*/
int Exoskeleton::get_c_health() { return c_health; }
int Exoskeleton::get_c_damage() { return c_damage; }
int Exoskeleton::get_c_agility() { return c_agility; }
int Exoskeleton::get_c_defence() { return c_defence; }

void Exoskeleton::set_c_health(int h) { c_health = h; }
void Exoskeleton::set_c_damage(int dmg) { c_damage = dmg; }
void Exoskeleton::set_c_defence(int def) { c_defence = def; }
void Exoskeleton::set_c_agility(int agi) { c_agility = agi; }



/*Spirit functions*/
int Spirit::get_c_health() { return c_health; }
int Spirit::get_c_damage() { return c_damage; }
int Spirit::get_c_agility() { return c_agility; }
int Spirit::get_c_defence() { return c_defence; }

void Spirit::set_c_health(int h) { c_health = h; }
void Spirit::set_c_damage(int dmg) { c_damage = dmg; }
void Spirit::set_c_defence(int def) { c_defence = def; }
void Spirit::set_c_agility(int agi) { c_agility = agi; }
