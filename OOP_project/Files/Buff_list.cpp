#include <iostream>
#include <vector>
#include "Buff_list.h"
#include "Buff.h"

using namespace std;

Buff_list::Buff_list() { ; }

void Buff_list::add_dmgbuff(int per, int tur) { damage_buffs.push_back(Buff(per, tur)); }
void Buff_list::add_defbuff(int per, int tur) { defence_buffs.push_back(Buff(per, tur)); }
void Buff_list::add_agibuff(int per, int tur) { agility_buffs.push_back(Buff(per, tur)); }

void Buff_list::move_buffs()
{
	for (int i = 0; i < damage_buffs.size() ; i++)
	{
		damage_buffs[i].move_turn();
	}
	for (int i = 0; i < defence_buffs.size() ; i++)
	{
		defence_buffs[i].move_turn();
	}
	for (int i = 0; i < agility_buffs.size() ; i++)
	{
		agility_buffs[i].move_turn();
	}
	cout << "Buffs have been updated" << endl;
}

void Buff_list::check_buffs()
{
	for (int i = 0; i < damage_buffs.size(); i++)
	{
		if (damage_buffs[i].get_turns() <= 0)
		{
			damage_buffs.erase(damage_buffs.begin()+i);
			i--; //Because i will point to the next item in the vector after the erase
		}
	}
	for (int i = 0; i < defence_buffs.size(); i++)
	{
		if (defence_buffs[i].get_turns() <= 0)
		{
			defence_buffs.erase(defence_buffs.begin() + i);
			i--; //Because i will point to the next item in the vector after the erase
		}
	}
	for (int i = 0; i < agility_buffs.size(); i++)
	{
		if (agility_buffs[i].get_turns() <= 0)
		{
			agility_buffs.erase(agility_buffs.begin() + i);
			i--; //Because i will point to the next item in the vector after the erase
		}
	}
}

void Buff_list::empty_buffs()
{
	damage_buffs.clear();
	defence_buffs.clear();
	agility_buffs.clear();
}

int Buff_list::get_all_dmg()
{
	int dmg = 0;
	for (int i = 0; i < damage_buffs.size(); i++)
	{
		dmg = dmg + damage_buffs[i].get_percentage();
	}
	return dmg;
}

int Buff_list::get_all_def()
{
	int def = 0;
	for (int i = 0; i < defence_buffs.size(); i++)
	{
		def = def + defence_buffs[i].get_percentage();
	}
	return def;
}

int Buff_list::get_all_agi()
{
	int agi = 0;
	for (int i = 0; i < agility_buffs.size(); i++)
	{
		agi = agi + agility_buffs[i].get_percentage();
	}
	return agi;
}