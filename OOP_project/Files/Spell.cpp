#include <iostream>
#include <string>
using namespace std;

class Spell
{
protected:
	string name;
	string type;
	int price;
	int min_lvl;
	double damage;
	int mana_req;
public:
	Spell(string nm, string tp, int pr, int mlvl, double dmg, int manr)
	{
		name = nm;
		type = tp;
		price = pr;
		min_lvl = mlvl;
		damage = dmg;
		mana_req = manr;
		cout << "I just created a Spell" << endl;
	}
	string get_name() {
		return name;
	}
	int get_price() { return price; }
	int get_minlvl() { return min_lvl; }
	double get_damage() { return damage; }
	int get_manareq() { return mana_req; }
	string get_type() { return type; } /*Types: Fire,Ice,Lighting*/
};