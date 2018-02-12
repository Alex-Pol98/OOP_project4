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
	int damage;
	int mana_req;
public:
	Spell(string nm, string tp, int pr, int mlvl, int dmg, int manr);
	string get_name();
	int get_price();
	int get_minlvl();
	double get_damage();
	int get_manareq();
	string get_type(); /*Types: Fire,Ice,Lighting*/
};
