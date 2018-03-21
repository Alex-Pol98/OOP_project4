#ifndef  ITEM
#define ITEM

#include <iostream>
#include <string>


using namespace std;

/*Abstract class Item*/
class Item
{
protected:
	string name;
	int price;
	int min_lvl;

public:
	Item(string nm, int pr, int mlvl);
	virtual string get_name() = 0;
	virtual int get_price() = 0;
	virtual int get_minlvl() = 0;
};


class Weapon : public Item
{
protected:
	int damage;
	bool hand; /*0=2_Handed 1=1_Handed*/

public:
	Weapon(string nm, int pr, int mlvl, int dmg, bool hd);
	int get_damage();
	bool get_hand();
	string get_name();
	int get_price();
	int get_minlvl();
	void print_info();
};


class Armor : public Item
{
protected:
	int defence;

public:
	Armor(string nm, int pr, int mlvl, int def);
	int get_def();
	string get_name();
	int get_price();
	int get_minlvl();
	void print_info();
};


class Potion :public Item
{
protected:
	string type; //Type of stat to increase (Health-Magic-Damage-Defence-Agility)
	int power;   // Determines how much will it increase its type
public:
	Potion(string nm, int pr, int mlvl, string tp, int pow);
	string get_type();
	string get_name();
	int get_power();
	int get_price();
	int get_minlvl();
	void print_info();
};

#endif //ITEM
