#pragma once
#include <iostream>
#include <vector>
#include "Buff.h"

using namespace std;

class Buff_list
{
	friend class Hero;
protected:
	vector <Buff> damage_buffs;   //These buffs concern the damage buffs
	vector <Buff> defence_buffs;  //These buffs concern the defence buffs
	vector <Buff> agility_buffs;  //These buffs concern the agility buffs
public:
	Buff_list();
	void add_dmgbuff(int per, int tur);   //Adds a damage buff
	void add_defbuff(int per, int tur);   //Adds a defence buff
	void add_agibuff(int per, int tur);   //Adds a agility buff
	void move_buffs();   //Decreases the turn of all the buffs
	void check_buffs();  //Checks if any buff has expired (turn==0)
	void empty_buffs();
	double get_all_dmg();  //Returns the multiplier caused by all the damage buffs
	double get_all_def();  //Returns the multiplier caused by all the defence buffs
	double get_all_agi();  //Returns the multiplier caused by all the agility buffs
};
