#include <iostream>
#include <string>
#include "Item.h"


using namespace std;


/*Item functions*/
Item::Item(string nm, int pr, int mlvl)
{
	name = nm;
	price = pr;
	min_lvl = mlvl;
	//cout << "I just created an Item" << endl;
}


/*Weapon functions*/
Weapon::Weapon(string nm, int pr, int mlvl, int dmg, bool hd) : Item(nm, pr, mlvl)
{
	damage = dmg;
	hand = hd;
}
int Weapon::get_damage() { return damage; }
bool Weapon::get_hand() { return hand; }
string Weapon::get_name() { return name; }
int Weapon:: get_price() { return price; }
int Weapon:: get_minlvl() { return min_lvl; }


void Weapon::print_info()
{
	cout << "Weapon information: " << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Damage: " << damage ;
	if (hand == 1)
	{
		cout << " (One-handed)" << endl;
	}
	else
	{
		cout << " (Two-handed)" << endl;
	}
}



/*Armor functions*/
Armor::Armor(string nm, int pr, int mlvl, int def) : Item(nm, pr, mlvl)
{
	defence = def;
}
int Armor::get_def() { return defence; }	
string  Armor::get_name() { return name; }
int  Armor::get_price() { return price; }
int  Armor::get_minlvl() { return min_lvl; }

void Armor::print_info()
{
	cout << "Armor information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << min_lvl << endl;
	cout << "Defence: " << defence << endl;
}


/*Potion functions*/
Potion::Potion(string nm, int pr, int mlvl, string tp,int pow) : Item(nm,pr,mlvl)
{
	type = tp;
	power = pow;
}
string Potion::get_type() { return type; }	
string Potion::get_name() { return name; }
int Potion::get_price() { return price; }
int Potion::get_minlvl() { return min_lvl; }

void Potion::print_info()
{
	cout << "Potion information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << min_lvl << endl;
}