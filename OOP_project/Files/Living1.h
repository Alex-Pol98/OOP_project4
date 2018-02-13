#include <iostream>
#include <string>

using namespace std;

class Living
{
protected:
	int lvl;
	int health;
public:
	Living(int h = 100, int l = 1)
	{
		lvl = l;
		health = h;
		cout << "I just created a Living "<< endl;
	}
	void set_health(int h);
};


/*Hero is an abstract class*/
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
	int get_magicpower();
	int get_strength();
	int get_dexterity();
	int get_agility();
	int get_money();
	int get_experience();
	int get_expreq();
	void print_stats();
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
	Warrior(int h = 150, int mag = 100, int str = 60, int dex = 30, int agi = 45) : Hero(h, mag, str, dex, agi)
	{
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup();
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
	void check_levelup();
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
	void check_levelup();
};



class Monster :public Living
{
protected:
	int damage;
	int defence;
	int agility;
public:
	Monster(int lvl_input) :Living(100, lvl_input) {}

	int get_damage();
	int get_defence();
	int get_agility();

	void set_damage(int dmg);
	void set_defence(int def);
	void set_agility(int agi);
	void print_stats();
};

class Dragon :public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Dragon(int lvl_input) :Monster(lvl_input)
	{
		set_health(lvl_input * 15 + 50);
		set_damage(20 + lvl_input * 10);
		set_defence(10 + lvl_input * 5);
		set_agility(10 + lvl_input * 5);

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);
};

class Exoskeleton : public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Exoskeleton(int lvl_input) :Monster(lvl_input)
	{
		set_health(lvl_input * 10 + 50);
		set_damage(10 + lvl_input * 5);
		set_defence(20 + lvl_input * 10);
		set_agility(10 + lvl_input * 5);

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);
};

class Spirit :public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Spirit(int lvl_input) :Monster(lvl_input)
	{
		set_health(lvl_input * 20 + 50);
		set_damage(10 + lvl_input * 5);
		set_defence(10 + lvl_input * 5);
		set_agility(20 + lvl_input * 10);

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);
};