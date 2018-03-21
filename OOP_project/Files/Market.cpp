#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Market.h"
#include "Spell.h"
#include "Item.h"

using namespace std;

/* The Ctor of the class Market that reads from a file the Items that will be available for the Heros to buy */
Market::Market(ifstream& inFile)
{
    // For the creation of the Market we've decided to create a File with 20 Items totally, 5 for each subclass and put them
    // to the vectors in the Ctor. The items in the .txt are in order by four(Weapon, Armor, Spell, Potion and again)

    string w_nm;                // Temporary variables for weapons, spells, armors and potions
    int w_pr;
    int w_mlvl;
    int w_dmg;
    string w_hd_temp;
    bool w_hd;
    string s_nm;
    string s_tp;
    int s_pr;
    int s_mlvl;
    int s_dmg;
    int s_manr;
    string a_nm;
    int a_pr;
    int a_mlvl;
    int a_def;
    string p_nm;
    int p_pr;
    int p_mlvl;
    string p_tp;
    int p_pow;

    if(inFile.is_open())
    {
        for(int i = 0; i < 5; i++)
        {
            inFile >> w_nm
                   >> w_pr
                   >> w_mlvl
                   >> w_dmg
                   >> w_hd_temp;

                   if(w_hd_temp == "ONE")
                        w_hd = true;
                    else
                        w_hd = false;

                   addWeapon(w_nm, w_pr, w_mlvl, w_dmg, w_hd);


            inFile >> s_nm
                   >> s_tp
                   >> s_pr
                   >> s_mlvl
                   >> s_dmg
                   >> s_manr;

                   addSpell(s_nm, s_tp, s_pr, s_mlvl, s_dmg, s_manr);

            inFile >> a_nm
                   >> a_pr
                   >> a_mlvl
                   >> a_def;

                   addArmor(a_nm, a_pr, a_mlvl, a_def);

            inFile >> p_nm
                   >> p_pr
                   >> p_mlvl
                   >> p_tp
                   >> p_pow;

                   addPotion(p_nm, p_pr, p_mlvl, p_tp, p_pow);
        }
    }
}

/** Access spells
 * returns The current value of spells
 */
 vector<Spell> Market::getSpells() { return spells; }

/** Access m_weapons
 * returns The current value of weapons
 */
 vector<Weapon> Market::getWeapons() { return weapons; }

/** Access m_armors
 * returns The current value of armors
 */
 vector<Armor> Market::getArmors() { return armors; }

/** Access m_potions
 * returns The current value of potions
 */
 vector<Potion> Market::getPotions() { return potions; }

/* Function to add Weapon from the .txt file to the Market's Vectors */
void Market::addWeapon(string nm, int pr, int mlvl, int dmg, bool hd)
{
    Weapon* newWeapon = new Weapon(nm, pr, mlvl, dmg, hd);
    this->weapons.push_back(*newWeapon);
}

/* Function to add Weapon from the .txt file to the Market's Vectors */
void Market::addSpell(string nm, string tp, int pr, int mlvl, int dmg, int manr)
{
    Spell* newSpell = NULL;

    if(tp == "Fire")
        newSpell = new FireSpell(nm, pr, mlvl, dmg, manr);
    else if(tp == "Lightning")
        newSpell = new LightningSpell(nm, pr, mlvl, dmg, manr);
    else if(tp == "Ice")
        newSpell = new IceSpell(nm, pr, mlvl, dmg, manr);

    this->spells.push_back(*newSpell);
}

/* Function to add Weapon from the .txt file to the Market's Vectors */
void Market::addArmor(string nm, int pr, int mlvl, int def)
{
    Armor* newArmor = new Armor(nm, pr, mlvl, def);
    this->armors.push_back(*newArmor);
}

/* Function to add Weapon from the .txt file to the Market's Vectors */
void Market::addPotion(string nm, int pr, int mlvl, string tp, int pow)
{
    Potion* newPotion = new Potion(nm, pr, mlvl, tp, pow);
    this->potions.push_back(*newPotion);
}

 void Market::print_spells()                                // Functions to print the <item>s of the Market
{
	for (unsigned int i = 0; i < spells.size(); i++)
	{
		cout << "Spell #" << i + 1 << ":" << endl;
		spells[i].print_info();
	}
}

void Market::print_weapons()
{
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		cout << "Weapon #" << i + 1 << ":" << endl;
		weapons[i].print_info();
	}
}

void Market::print_armors()
{
	for (unsigned int i = 0; i < armors.size(); i++)
	{
		cout << "Armor #" << i + 1 << ":" << endl;
		armors[i].print_info();
	}
}

void Market::print_potions()
{
	for (unsigned int i = 0; i < potions.size(); i++)
	{
		cout << "Potion #" << i + 1 << ":" << endl;
		potions[i].print_info();
	}
}

void Market::print_all()
{
	cout << "SPELLS:" << endl << endl;
	print_spells();
	cout << "_____________________________________________" << endl;
	cout << "WEAPONS:" << endl << endl;
	print_weapons();
	cout << "_____________________________________________" << endl;
	cout << "ARMORS:" << endl << endl;
	print_armors();
	cout << "_____________________________________________" << endl;
	cout << "POTIONS:" << endl << endl;
	print_potions();
	cout << "_____________________________________________" << endl;
}

