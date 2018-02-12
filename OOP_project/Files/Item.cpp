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
	cout << "I just created an Item" << endl;
}


/*Weapon functions*/
Weapon::Weapon(string nm, int pr, int mlvl, double dmg, bool hd) : Item(nm, pr, mlvl)
{
	damage = dmg;
	hand = hd;
}
double Weapon::get_damage() { return damage; }
bool Weapon::get_hand() { return hand; }
string Weapon::get_name() { return name; }
int Weapon:: get_price() { return price; }
int Weapon:: get_minlvl() { return min_lvl; }



/*Armor functions*/
Armor::Armor(string nm, int pr, int mlvl, double def) : Item(nm, pr, mlvl)
{
	defence = def;
}
double Armor::get_def() { return defence; }	
string  Armor::get_name() { return name; }
int  Armor::get_price() { return price; }
int  Armor::get_minlvl() { return min_lvl; }


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
