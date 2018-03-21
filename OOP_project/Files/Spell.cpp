#include <iostream>
#include <string>
#include "Spell.h"

using namespace std;

/*Spell functions*/
Spell::Spell(string nm, int pr, int mlvl, int dmg, int manr)
{
	name = nm;
	price = pr;
	min_lvl = mlvl;
	damage = dmg;
	mana_req = manr;
	//cout << "I just created a Spell" << endl;
}

Spell::~Spell() { } // cout << "I just deleted a spell" << endl; }

/* Getter for the Spell's Fields */
string Spell::get_name() { return name; }
int Spell::get_price() { return price; }
int Spell::get_minlvl() { return min_lvl; }
int Spell::get_damage() { return damage; }
int Spell::get_manareq() { return mana_req; }
string Spell::get_type() { return type; }

void Spell::print_info()
{
	cout << "\tSpell information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << min_lvl << endl;
	cout << "Damage: " << damage << endl;
	cout << "Mana required: " << mana_req << endl;
	cout << endl;
}

/* Ctor for the subClass FireSpell */
FireSpell::FireSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(nm, pr, mlvl, dmg, manr)
{
    Spell::type = "Fire";
}

/* Ctor for the subClass LightningSpell */
LightningSpell::LightningSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(nm, pr, mlvl, dmg, manr)
{
    Spell::type = "Lightning";
}

/* Ctor for the subClass IceSpell */
IceSpell::IceSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(nm, pr, mlvl, dmg, manr)
{
    Spell::type = "Ice";
}
