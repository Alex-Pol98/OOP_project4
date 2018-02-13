#include <iostream>
#include <string>
#include "Spell.h"

using namespace std;

/*Spell functions*/
Spell::Spell(string nm, string tp, int pr, int mlvl, int dmg, int manr)
{
	name = nm;
	type = tp;
	price = pr;
	min_lvl = mlvl;
	damage = dmg;
	mana_req = manr;
	//cout << "I just created a Spell" << endl;
}

Spell::~Spell() { }//cout << "I just deleted a spell" << endl; }

string Spell::get_name() 
{
	return name;
}

int Spell::get_price() { return price; }
int Spell::get_minlvl() { return min_lvl; }
double Spell::get_damage() { return damage; }
int Spell::get_manareq() { return mana_req; }
string Spell::get_type() { return type; }

void Spell::print_info()
{
	cout << "Spell information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << min_lvl << endl;
	cout << "Damage: " << damage << endl;
	cout << "Mana required: " << mana_req << endl;
}
