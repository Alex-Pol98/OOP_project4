#pragma once
#include <iostream>
#include <vector>
#include "Buff.h"

using namespace std;

class Buff_list
{
	friend class Hero;
protected:
	vector <Buff> damage_buffs;
	vector <Buff> defence_buffs;
	vector <Buff> agility_buffs;
public:
	Buff_list();
	void add_dmgbuff(int per, int tur);
	void add_defbuff(int per, int tur);
	void add_agibuff(int per, int tur);
	void move_buffs();
	void check_buffs();
	void empty_buffs();
	int get_all_dmg();
	int get_all_def();
	int get_all_agi();
};
