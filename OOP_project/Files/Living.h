#ifndef  LIVING
#define LIVING

#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "Buff.h"
#include "Buff_list.h"

using namespace std;

class Living
{
protected:
	int lvl;
	int health;
public:
	Living(int h = 100, int l = 1)          // LIVING STARTING: HEALTH 100, LEVEL 1
	{
		lvl = l;
		health = h;
	}
	void set_health(int h);
	int get_level();
	int get_health();
};


/*Hero is an abstract class*/
class Hero :public Living
{
protected:
	string name;
	int magic_power;
	int strength;
	int dexterity;
	int agility;
	int money;
	int experience;
	int exp_req;
	Armor* armor;
	Weapon* weapon;
public:
	Inventory inv;
	Buff_list buffs;
public:
	Hero(string nm, int h, int mag, int str, int dex, int agi) :Living(h)
	{
		name = nm;
		magic_power = mag;
		strength = str;
		dexterity = dex;
		agility = agi;
		money = 500;                            // HERO STARTING: MONEY 500, EXPERIENCE 0, EXPERIENCE_REQUIRED 1000
		experience = 0;
		exp_req = 1000;
		armor = NULL;
		weapon = NULL;
	}
	virtual void check_levelup() = 0;
	string get_name();
	int get_magicpower();
	int get_strength();
	int get_dexterity();
	int get_agility();
	int get_money();
	int get_experience();
	int get_expreq();
	virtual void print_stats();

	void equip_armor();
	void equip_weapon();
	void equip_weapon(int no);
	void equip_armor(int no);

	//These functions should not be accessed from a Hero class perspective
	virtual void restore_health(int value)
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }
	virtual void restore_magicpower(int value)
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }
	virtual void receive_damage(int dmg)
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }
	virtual int get_chealth()
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }
	virtual int get_cmagicpower()
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }
	virtual void sub_magicpower(int value)
	{
	    cout << "BAD ACCESS!" << endl;
	    exit(1);
    }


	void addExperience(int value);
	void addMoney(int mon);
	void subMoney(int mon);
	void tossArmor();
	void tossWeapon();
	Armor* getEquippedArmor();
	Weapon* getEquippedWeapon();
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
	Warrior(string nm, int h = 150, int mag = 100, int str = 60, int dex = 30, int agi = 45) : Hero(nm,h, mag, str, dex, agi)
	{   // WARRIOR STARTING: HEALTH 150,MAGIC_POWER 100, STRENGTH 60, DEXTERITY 30, AGILITY 45
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup();
	void sub_magicpower(int value);
	void restore_health(int value);
	void restore_magicpower(int value);
	void receive_damage(int dmg);
	int get_chealth();
	int get_cmagicpower();
	void print_stats();
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
	Sorcerer(string nm, int h = 130, int mag = 250, int str = 30, int dex = 60, int agi = 45) : Hero(nm,h, mag, str, dex, agi)
	{   // SORCERER STARTING: HEALTH 130,MAGIC_POWER 250, STRENGTH 30, DEXTERITY 60, AGILITY 45
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup();
	void sub_magicpower(int value);
	void restore_health(int value);
	void restore_magicpower(int value);
	int get_chealth();
	void receive_damage(int dmg);
	int get_cmagicpower();
	void print_stats();
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
	Paladin(string nm, int h = 180, int mag = 140, int str = 60, int dex = 45, int agi = 30) : Hero(nm,h, mag, str, dex, agi)
	{   // PALADIN STARTING: HEALTH 180,MAGIC_POWER 140, STRENGTH 60, DEXTERITY 45, AGILITY 30
		c_health = health;
		c_magicpower = magic_power;
		c_strength = strength;
		c_dexterity = dexterity;
		c_agility = agility;
	}
	void check_levelup();
	void sub_magicpower(int value);
	void restore_health(int value);
	void restore_magicpower(int value);
	int get_chealth();
	void receive_damage(int dmg);
	int get_cmagicpower();
	void print_stats();
};



class Monster :public Living
{
protected:
	int damage;
	int defence;
	int agility;
public:
	Buff_list buffs;
public:
	Monster(int lvl_input) :Living(100, lvl_input) {}

	//These functions should not be accessed from a Monster class perspective
	virtual void receive_damage(int dmg) { cout << "BAD ACCESS!" << endl; };
	virtual int get_c_health() { cout << "BAD ACCESS!" << endl; return 0; };

	int get_damage();
	int get_defence();
	int get_agility();

	void set_damage(int dmg);
	void set_defence(int def);
	void set_agility(int agi);
	void print_stats();
	virtual void print_data() { ; }
};

class Dragon :public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Dragon(int lvl_input) :Monster(lvl_input)   //The stats of a dragon depend on the level that has been inputed.
	{
		set_health(lvl_input * 15 + 50);        // HEALTH = LEVEL * 15 + 50
		set_damage(20 + lvl_input * 10);        // DAMAGE = LEVEL * 10 +20
		set_defence(10 + lvl_input * 5);        // DEFENCE = LEVEL * 5 + 10
		set_agility(10 + lvl_input * 5);        // AGILITY = LEVEL * 5 + 10

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();
	void print_data();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);
	void receive_damage(int dmg);
};

class Exoskeleton : public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Exoskeleton(int lvl_input) :Monster(lvl_input)  //The stats of an Exoskeleton depend on the level that has been inputed.
	{
		set_health(lvl_input * 10 + 50);            // HEALTH = LEVEL * 10 + 50
		set_damage(10 + lvl_input * 5);             // DAMAGE = LEVEL * 5 + 10
		set_defence(20 + lvl_input * 10);           // DEFENCE = LEVEL * 10 + 20
		set_agility(10 + lvl_input * 5);            // AGILITY = LEVEL * 5 + 10

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();
	void print_data();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);

	void receive_damage(int dmg);
};

class Spirit :public Monster
{
protected:
	int c_health;
	int c_damage;
	int c_defence;
	int c_agility;
public:
	Spirit(int lvl_input) :Monster(lvl_input)   //The stats of a Spirit depend on the level that has been inputed.
	{
		set_health(lvl_input * 20 + 50);        // HEALTH = LEVEL * 20 + 50
		set_damage(10 + lvl_input * 5);         // DAMAGE = LEVEL * 5 + 10
		set_defence(10 + lvl_input * 5);        // DEFENCE = LEVEL * 5 + 10
		set_agility(20 + lvl_input * 10);       // AGILITY = LEVEL * 10 + 20

		c_health = health;
		c_damage = damage;
		c_defence = defence;
		c_agility = agility;
	}

	int get_c_health();
	int get_c_damage();
	int get_c_agility();
	int get_c_defence();
	void print_data();

	void set_c_health(int h);
	void set_c_damage(int dmg);
	void set_c_defence(int def);
	void set_c_agility(int agi);

	void receive_damage(int dmg);
};

#endif //LIVING
