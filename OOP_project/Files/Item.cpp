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
	virtual string get_name() = 0;
	Item(string nm, int pr, int mlvl)
	{
		name = nm;
		price = pr;
		min_lvl = mlvl;
		cout << "I just created an Item" << endl;
	}
	virtual int get_price() = 0;
	virtual int get_minlvl() = 0;
};

class Weapon :public Item
{
protected:
	double damage;
	bool hand; /*0=2_Handed 1=1_Handed*/

public:
	Weapon(string nm, int pr, int mlvl, double dmg, bool hd) : Item(nm, pr, mlvl)
	{
		damage = dmg;
		hand = hd;
	}
	double get_damage() { return damage; }
	bool get_hand() { return hand; }
	int get_price() { return price; }
	int get_minlvl() { return min_lvl; }
	string get_name() { return name; }
};

class Armor : public Item
{
protected:
	double defence;
	
public:
	Armor(string nm, int pr, int mlvl, double def) : Item(nm, pr, mlvl)
	{
		defence = def;
	}
	double get_def() { return defence; }
	int get_price() { return price; }
	int get_minlvl() { return min_lvl; }
	string get_name() { return name; }
};

class Potion :public Item
{
protected:
	string type; /*Type of stat*/
	int power;
public:
	Potion(string nm, int pr, int mlvl, string tp,int pow) : Item(nm,pr,mlvl)
	{
		type = tp;
		power = pow;
	}
	string get_type() { return type; }
	int get_price() { return price; }
	int get_minlvl() { return min_lvl; }
	string get_name() { return name; }
};