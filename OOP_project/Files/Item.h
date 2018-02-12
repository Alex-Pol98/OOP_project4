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


class Weapon :public Item
{
protected:
	double damage;
	bool hand; /*0=2_Handed 1=1_Handed*/

public:
	Weapon(string nm, int pr, int mlvl, double dmg, bool hd);
	double get_damage();
	bool get_hand();
	string get_name();
	int get_price();
	int get_minlvl();
};

class Armor : public Item
{
protected:
	double defence;

public:
	Armor(string nm, int pr, int mlvl, double def);
	double get_def();
	string get_name();
	int get_price();
	int get_minlvl();
};

class Potion :public Item
{
protected:
	string type; /*Type of stat*/
	int power;
public:
	Potion(string nm, int pr, int mlvl, string tp, int pow);
	string get_type();
	string get_name();
	int get_price();
	int get_minlvl();
};
