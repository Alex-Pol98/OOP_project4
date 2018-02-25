#ifndef MARKET_H
#define MARKET_H


#include <iostream>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Spell.h"

using namespace std;

class Market
{
    public:
        Market(ifstream& inFile);
        vector<Spell> getSpells();
        vector<Weapon> getWeapons();
        vector<Armor> getArmors();
        vector<Potion> getPotions();
        void print_weapons();
        void print_armors();
        void print_spells();
        void print_potions();
        void print_all();
        void addWeapon(string nm, int pr, int mlvl, int dmg, bool hd);
        void addSpell(string nm, string tp, int pr, int mlvl, int dmg, int manr);
        void addArmor(string nm, int pr, int mlvl, int def);
        void addPotion(string nm, int pr, int mlvl, string tp, int pow);

    private:
        vector<Spell> spells;
        vector<Weapon> weapons;
        vector<Armor> armors;
        vector<Potion> potions;
};


#endif

