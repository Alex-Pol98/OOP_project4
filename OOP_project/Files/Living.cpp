#include <iostream>
#include <string>

using namespace std;

class Living
{
protected:
	int lvl;
	int health;
public:
	Living()
	{
		lvl = 1;
		health = 100;
	}
	Living(int h=100, int l=1)
	{
		lvl = l;
		health = h;
		cout << "I just created a Living" << endl;
	}
};


class Hero :public Living
{
protected:
	int magic_power;
	int strength;
	int dexterity;
	int agility;
	int money;
	int experience;
	int exp_req;


public:
	Hero(int h, int mag, int str, int dex, int agi) :Living(h)
	{
		magic_power = mag;
		strength = str;
		dexterity = dex;
		agility = agi;
		money = 0;
		experience = 0;
		exp_req = 1000;
	}
	virtual void check_levelup() = 0;
	int get_magicpower() { return magic_power; }
	int get_strength() { return strength; }
	int get_dexterity() { return dexterity; }
	int get_agility() { return agility; }
	int get_money() { return money; }
	int get_experience() { return experience; }
	int get_expreq() { return exp_req; }

};

class Warrior :public Hero
{
protected:
	/*These stats concern the current stats of each hero*/
	int c_health;
	int c_magicpower;
	int c_strength;
	int c_dexterity;
	int c_agility;
		
public:
	Warrior (int h=150, int mag=100, int str=60, int dex=30, int agi=45) : Hero(h, mag, str, dex, agi)
	{
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup()
	{
		if (experience >= exp_req)
		{
			experience = experience - exp_req;
			exp_req = exp_req * 1.2 + 100 *lvl;
			lvl++;
			strength = +10;
			dexterity = +5;
			agility = +7;
			health = +50;
			magic_power = +15;
		}
	}
};

class Sorcerer :public Hero
{
protected:
	/*These stats concern the current stats of each hero*/
	int c_health;
	int c_magicpower;
	int c_strength;
	int c_dexterity;
	int c_agility;
public:
	Sorcerer(int h = 130, int mag = 250, int str = 30, int dex = 60, int agi = 45) : Hero(h, mag, str, dex, agi)
	{
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup()
	{
		if (experience >= exp_req)
		{
			experience = experience - exp_req;
			exp_req = exp_req * 1.2 + 100 *lvl;
			lvl++;
			strength = +5;
			dexterity = +10;
			agility = +7;
			health = +30;
			magic_power = +35;
		}
	}
};

class Paladin :public Hero
{
protected:
	/*These stats concern the current stats of each hero*/
	int c_health;
	int c_magicpower;
	int c_strength;
	int c_dexterity;
	int c_agility;
public:
	Paladin(int h = 180, int mag = 140, int str = 60, int dex = 45, int agi = 30) : Hero(h, mag, str, dex, agi)
	{
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup()
	{
		if (experience >= exp_req)
		{
			experience = experience - exp_req;
			exp_req = exp_req * 1.2 + 100 *lvl;
			lvl++;
			strength = +10;
			dexterity = +7;
			agility = +5;
			health = +60;
			magic_power = +25;
		}
	}
};

/*_______________________________________________________________________________________________________________________________________________________________________*/
class Monster :public Living
{
protected:
	int damage;
	int defence;
	int agility;
public:
	Monster(int h,int l, int dmg, int def,int agi) :Living(h,l)
	{
		damage = dmg;
		defence = def;
		agility = agi;
	}
	int get_damage() { return damage; }
	int get_defence() { return defence; }
};

class Dragon :public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:

	Dragon(int l, int h, int dmg, int def, int agi) :Monster(h, l)
	{
		h = 100 + 40 * l;
		dmg = (30 + 12 * l);
		def = (7 + 3 * l);

	}
};