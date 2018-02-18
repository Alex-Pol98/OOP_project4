#ifndef MARKET_H
#define MARKET_H


#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"

using namespace std;

class Market
{
    public:
        Market();
        vector<Spell> getSpells();
        vector<Weapon> getWeapons();
        vector<Armor> getArmors();
        vector<Potion> getPotions();
        void print_weapons();
        void print_armors();
        void print_spells();
        void print_potions();
        void print_all();

    private:
        vector<Spell> spells;
        vector<Weapon> weapons;
        vector<Armor> armors;
        vector<Potion> potions;
};


#endif

