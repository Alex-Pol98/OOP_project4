#include <cstdlib>
#include "CommonSquare.h"
#include "Square.h"
#include "Grid.h"
#include "Buff.h"
#include "Buff_list.h"

/* Ctor of the Common Square */
CommonSquare::CommonSquare(int givenX, int givenY):  Square(SQUARE_TYPE_COMMON, givenX, givenY)
{}                                  // it calls the Square Ctor with its dimensions and the int value for the Square's Type field

/* Dtor of the Common Square */
CommonSquare::~CommonSquare()
{}

/* Function for when the user is on a Common Square */
void CommonSquare::displayMenu(Hero** myHeroes)
{
    // There are two options: Battle or noBattle depending on the outcome of the rand and the BATTLE_POSSIBILITY = 50
    int r = rand() % 101;
    if(r >= BATTLE_POSSIBILITY)
        battle(myHeroes);
    else
        noBattle(myHeroes);

}

/* Function for the battle ( If battle does happen ) */
void CommonSquare::battle(Hero** myHeroes)
{
    cout << "There will be a battle in this square\n\n\tBATTLE" << endl;
    bool heroesWon;                 // variable to see if the Heroes won the Monsters
    int winExp;                     // variable about how much XP will the heroes gain if they win
    int winMoney;                   // variable about how much money  will the heroes gain if they win

    Monster* Monsters[4];
	int lvl = myHeroes[0]->get_level();
	fill_monsters(Monsters,lvl);    //Spawns the monsters after their creation
	winExp = get_xp(Monsters);      // calculation of the XP and Money that the Heroes will gain if they win
	winMoney = get_money(Monsters);

	while(!heroes_all_dead(myHeroes) && !monsters_all_dead(Monsters))
    {                                           // while the heroes and the monsters are alive
        battleHerosTurn(myHeroes, Monsters);    // firstly heroes turn, then monsters turn and then
        battleMonstersTurn(myHeroes, Monsters); // we have the restore of heroes stats in each round
        herosRestore(myHeroes);
    }

    if(monsters_all_dead(Monsters))                 // if the monsters are dead, the heroes won so we have heroesWon to be true and
    {                                               // print of relevant message
        heroesWon = true;
        cout << "\n\tHeroes Won!!" << endl << endl;
    }
    else                                            // else the monsters won so we have heroesWon to be false and print of relevant message
    {
        heroesWon = false;
        cout << "\n\tMonsters Won.." << endl << endl;
    }
                                                        // in the end of the battle the afterBattle function is called to determine the aftermath
    afterBattle(myHeroes, heroesWon, winExp, winMoney); // of the battle
}

/* Function for the Heroes' turn in the battle */
void CommonSquare::battleHerosTurn(Hero** myHeroes, Monster* Monsters[4])
{
    cout << "Heroes' Turn!" << endl;
    int option;                                                 // variables for the option the user chooses and a boolean that checks if the
    bool doneTurn;                                              // user has done his turn( we consider that a turn is done only if the user
                                                                // attacks, casts spell or uses a potion
    for(int i = 0; i < 3; i++)                                  // For the Max of 3 Heroes, if they exist(so they are not Null), and they are
    {                                                           // alive(their health > 0) and if the monsters haven't died while the heroes
        if(myHeroes[i] != NULL && myHeroes[i]->get_chealth() > 0 && !monsters_all_dead(Monsters))
        {                                                       // turn is done then
            doneTurn = false;
            while(doneTurn == false)                            // while the doneTurn is false
            {
                cout << "\tHero " << i << " Options:" << endl;  // we show the user for each hero their options, read the user's option and
                showBattleOptions();                            // check if its valid
                cin >> option;

                while(option != 1 && option != 2 && option != 3 &&
                      option != 4 && option != 5)
                {
                    cout << "Wrong Option\n";
                    showBattleOptions();
                    cin >> option;
                }

                if(option == 1)                                 // the first option is to attack the monsters with the attack function which
                    doneTurn = attack(myHeroes[i], Monsters);   // returns true to the doneTurn if the attack was done
                else if(option == 2)
                    doneTurn = castSpell(Monsters, myHeroes[i]);// the second option is to cast a spell with the castSpell function which returns
                else if(option == 3)                            // true to the doneTurn if the cast was done
                    doneTurn = use(myHeroes[i]);
                else if(option == 4)                            // the third option is to use a potion with the use function which returns also
                    myHeroes[i]->equip_weapon();                // true to the doneTurn if the usage was done
                else if(option == 5)
                    myHeroes[i]->equip_armor();                 // the fourth and fifth option are to equip a weapon or an armor to the hero(the
            }                                                   // user can change weapons and armors without losing the round

            update_buffs(myHeroes, Monsters);                   // in the end we update the buffs
        }
    }
}

/* Function for Hero's Restore after each round */
void CommonSquare::herosRestore(Hero** myHeroes)
{
    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)                         // for each hero(if he exists and is alive) we restore his health and magicpower by 10
        {                                               // and print his stats
            if(myHeroes[i]->get_chealth() != 0)
            {
                myHeroes[i]->restore_health(10);        // Health and MagicPower Restore By 10
                myHeroes[i]->restore_magicpower(10);
                myHeroes[i]->print_stats();
            }
        }
    }
}

/* Function for the Monsters' turn in the battle */
void CommonSquare::battleMonstersTurn(Hero* myHeroes[3], Monster* Monsters[4])
{
    if(!heroes_all_dead(myHeroes))                  // if the heroes are alive we print that its Monsters' turn and then for each monster
    {                                               // if the heroes are alive we have a random number to attack a random hero. Each Monster
        cout << "Monsters' Turn!" << endl;          // if it exists(not NULL) we print that its attacking and we find a random Hero that exists
        for (int i = 0; i < 4; i++)                 // and is alive (through the while loop) for the monster to attack. Then we print the target,
        {                                           // hurt the Hero through the receiveDamage function(the damage is calculated according to
            if(!heroes_all_dead(myHeroes))          // the Monster's damage multiplied by the Damage Buff of it). Then we print the remaining
            {                                       // Hero's health and update the Buffs
                int h_att;                          // variable for the rand()
                if (Monsters[i] != NULL)
                {
                    cout << "The #" << i << " monster is attacking!" << endl;
                    h_att = rand() % 3;
                    while (myHeroes[h_att] == NULL || myHeroes[h_att]->get_chealth() == 0)
                    {
                        h_att = rand() % 3;
                    }
                    cout << "A Monster will attack the #" << h_att << " Hero!" << endl;
                    myHeroes[h_att]->receive_damage(Monsters[i]->get_damage()*Monsters[i]->buffs.get_all_dmg()); // Damage = MonstersDamage*MonstersDamageBuff
                    cout << "Health remaining= " << myHeroes[h_att]->get_chealth() << endl;
                    update_buffs(myHeroes, Monsters);
                }
            }
            else
            {
                cout << "Monster cannot attack because the Heroes are dead" << endl;
            }
        }
    }
}

/* Function of what to do in case there is no battle in the Common Square ( If battle does not happen ) */
void CommonSquare::noBattle(Hero** myHeroes)
{
    cout << "There will be no battle in this square" << endl;
    int option = 0;                                         // we print that there is no battle. Then for each hero if he exists we show the user
                                                            // the options through the showNoBattleOptions and read their choice and force him
    for(int i = 0; i < 3; i++)                              // to give a valid option through the while
    {
        if(myHeroes[i] != NULL)
        {
            cout << "\tHero " << i << " Options:" << endl;
            while(option != 6)                              // the user can access the menu and do whatever he wants until he choses to
            {                                               // return to the main menu
                showNoBattleOptions();
                cin >> option;

                while(option != 1 && option != 2 && option != 3 &&
                      option != 4 && option != 5 && option != 6)
                {
                    cout << "Wrong Option\n";
                    showNoBattleOptions();
                    cin >> option;
                }

                if(option == 1)                             // the first option is to show the user the hero's inventory through the print_all
                    myHeroes[i]->inv.print_all();           // function
                else if(option == 2)                        // the second is to equip a weapon to the hero through the equip_weapon function
                    myHeroes[i]->equip_weapon();
                else if(option == 3)                        // third option is to equip an armor to the hero through the equip_armor function
                    myHeroes[i]->equip_armor();
                else if(option == 4)                        // the fourth option is to use a potion through the use function
                    use(myHeroes[i]);
                else if(option == 5)                        // the fifth option is to show the hero's stats through the print_all function
                    myHeroes[i]->print_stats();
                else if(option == 6)                        // and the sixth is to return to the main menu, so we do nothing
                {

                }
            }

            option = 0;                                     // here we set the option variable back to 0 for the next hero loop
        }
    }
}

/* Function to show a menu to the user to choose what to do in the common square if not battle happens */
void CommonSquare::showNoBattleOptions()
{
    cout << "\n Please choose your option:" << endl;            // The Options are:
    cout << " Check your Inventory (Press 1)" << endl;          // check the inventory
    cout << " Change Equipped Weapon (Press 2)" << endl;        // change equipped weapon
    cout << " Change Equipped Armor (Press 3)" << endl;         // change equipped armor
    cout << " Use a Potion (Press 4)" << endl;                  // use a potion
    cout << " Show Hero's Information (Press 5)" << endl;       // see hero's info
    cout << " Continue your journey (Press 6)" << endl << endl; // return to the main Menu
}

/* Function to show a menu to the user to choose what to do in the battle */
void CommonSquare::showBattleOptions()
{
    cout << "\nPlease choose your option:" << endl;             // The options are:
    cout << "Attack (Press 1)" << endl;                         // attack a monster
    cout << "Cast Spell (Press 2)" << endl;                     // cast a spell on a monster
    cout << "Use a Potion (Press 3)" << endl;                   // use a potions
    cout << "Change Equipped Weapon (Press 4)" << endl;         // change equipped weapon
    cout << "Change Equipped Armor (Press 5)" << endl << endl;  // change equipped armor
}

/* Function to create the monsters in the battle */
void CommonSquare::fill_monsters(Monster* Monsters[4],int lvl)
{
    int counter = 0;                                    // variable for counting the Monsters created
	int tmp;                                            // variable for random number: at first a dragon, exoskeleton or spirit is created(depending
	tmp = rand() % 3;                                   // on the rand()). Then there is 50% possibility for a monster to be created, else
	if (tmp == 0)                                       // its set to Null
	{
		Monsters[0] = new Dragon(lvl + rand() % 3 - 1); // Each monster can be a level higher, the same or a level lower than the heroes.
		counter++;                                      // Each time a monster is created we increment the counter
	}
	else if (tmp == 1)
	{
		Monsters[0] = new Exoskeleton(lvl + rand() % 3 - 1);
		counter++;
	}
	else
	{
		Monsters[0] = new Spirit(lvl + rand() % 3 - 1);
		counter++;
	}

	for (int i = 1; i < 4; i++)
	{
		tmp = rand() % 2;
		if (tmp == 0)
		{
			Monsters[i] = NULL;
		}
		else
		{
			tmp = rand() % 3;
			if (tmp == 0)
			{
				Monsters[i] = new Dragon(lvl + rand() % 3 - 1);
				counter++;
			}
			else if (tmp == 1)
			{
				Monsters[i] = new Exoskeleton(lvl + rand() % 3 - 1);
				counter++;
			}
			else
			{
				Monsters[i] = new Spirit(lvl + rand() % 3 - 1);
				counter++;
			}
		}
	}                                                       // In the end we print the Monsters' creation
	cout << counter << " Monsters spawned" << endl;
}

/* Function to print out what monsters exist in the battle field for the user to choose where to attack */
void CommonSquare::print_monsters_in_battle(Monster* monsters[4])
{
	cout << "\tMONSTERS IN BATTLE: { ";                     // We print the Monsters' Positions in the battle:
	for (int i = 0; i < 4; i++)                             // For each Monster if it exists we put its number in a row(starting from zero)
	{                                                       // or else we print an "_" in its place showing that it doesnt exist
		if (monsters[i] != NULL)
		{
			cout << i << " ";
		}
		else
        {
            cout << "_ ";
        }
	}
	cout << "}" << endl;
	for (int i = 0; i < 4; i++)                             // Then for each Monster we print its number and some info through the print_data
	{                                                       // function
		if (monsters[i] != NULL)
		{
			cout <<"#"<< i << " - Monster's data:" << endl;
			monsters[i]->print_data();
		}
	}
}

/* Function for the Heroes to attack the monsters in the battle function */
bool CommonSquare::attack(Hero* myHero, Monster* Monsters[4])
{
    int damage;                                         // variable for the attack monster
    int mchoice;                                        // variable for the Monster  Target
    int doneTurn = false;                               // boolean variable to check if the turn is done
    if(myHero->getEquippedWeapon() != NULL)             // If the Hero has an equipped Weapon
    {                                                   // Damage = HerosStrength/4*DamageBuff + WeaponsDamage
        damage = (myHero->getEquippedWeapon()->get_damage() + myHero->get_strength()/4)*myHero->buffs.get_all_dmg();
    }
    else                                                // If the Hero has not an equipped weapon
    {                                                   // Damage = HerosStrength/4*DamageBuff
        damage = (myHero->get_strength()/4)*myHero->buffs.get_all_dmg();
    }
    print_monsters_in_battle(Monsters);                 // then we show the user the Monsters' position through the print_monsters_in_battle
    cout << "Select the monster you want to attack: " << endl;
    cin >> mchoice;                                     // function and read his target and force him to give a valid target
    cout << endl;
    while (mchoice > 3 || Monsters[mchoice] == NULL)
    {
        cout << "Bad input!\nPlease choose again:" << endl;
        cin >> mchoice;
    }
    Monsters[mchoice]->receive_damage(damage);          // then the Monster is hurt through the receive_damage function
    doneTurn = true;                                    // doneTurn is set to true as the attack was done
    if (Monsters[mchoice]->get_c_health() == 0)         // and if the Monster is dead we delete it
    {
        delete Monsters[mchoice];
        Monsters[mchoice] = NULL;
    }
    else                                                // else we print its remaining life
    {
        cout << "Monster Remaining Health = " << Monsters[mchoice]->get_c_health() << endl;
    }

    return doneTurn;                                    // finally we return doneTurn
}

/* Function for the heroes to cast a spell to the monsters in the battle function */
bool CommonSquare::castSpell(Monster* Monsters[4], Hero* myHero)
{
    bool doneTurn = false;                              // same as attack function

    if (myHero->inv.is_spell_list_empty() == true)      // if there are no spells we print relevant message
    {
        cout << "The spell list is empty!" << endl;
    }
    else                                                // else the user choses the spell he wants to use, checks if the hero has enough Mana
    {                                                   // for it and then reduces it from the hero. Then the damage of the spell is calculated,
        int schoice;                                    // the user choses target and the selected monster gets hurt and doneTurn is set to true
        myHero->inv.print_spells();                     // Then if the Monster is alive we add a Buff through add_buff
        cout << "Please input the number of the spell to use: " << endl;
        cin >> schoice;
        cout << endl;
        while (schoice > myHero->inv.get_spell_list_size() || schoice < 1)
        {
            cout << "Bad input!\nPlease choose again:" << endl;
            cin >> schoice;
        }

        {
            schoice--;                                  // schoice is reduced to match the vector starting at 0 and not 1
            if (myHero->inv.get_spell_manareq(schoice) > myHero->get_magicpower())
            {
                cout << "Not enough Mana to cast the spell!" << endl;
            }
            else
            {
                int damage;
                int mchoice;
                myHero->sub_magicpower(myHero->inv.get_spell_manareq(schoice)); // Damage = SpellDamage + herosDexterity/3*DamageBuff
                damage = (myHero->inv.get_spell_damage(schoice) + (myHero->get_dexterity() / 3))*myHero->buffs.get_all_dmg();
                print_monsters_in_battle(Monsters);
                cout << "Select the monster you want to cast the spell to: ";
                cin >> mchoice;
                cout << endl;
                while (mchoice > 3 || Monsters[mchoice] == NULL)
                {
                    cout << "Bad input!\nPlease choose again:" << endl;
                    cin >> mchoice;
                }

                Monsters[mchoice]->receive_damage(damage);
                doneTurn = true;
                if (Monsters[mchoice]->get_c_health() == 0)
                {
                    delete Monsters[mchoice];
                    Monsters[mchoice] = NULL;
                }
                else
                {
                    if (myHero->inv.get_spell_type(schoice) == "Fire")
                    {
                        Monsters[mchoice]->buffs.add_dmgbuff(-5, 10);  //If its a firespell then it decreases the damage by 5% for 10 rounds.
                    }
                    else if (myHero->inv.get_spell_type(schoice) == "Ice")
                    {
                        Monsters[mchoice]->buffs.add_defbuff(-5, 10);  //If its an icespell then it decreases the defence by 5% for 10 rounds.
                    }
                    else
                    {
                        Monsters[mchoice]->buffs.add_agibuff(-5, 10);  //If its a lightningspell then it decreases the agility by 5% for 10 rounds.
                    }
                }
            }
        }
    }

    return doneTurn;                                                    // and in the end doneTurn is returned
}

/* Function for the hero to use potion in the battle function */
bool CommonSquare::use(Hero* myHero)
{
    bool doneTurn = false;                                              // same as Spells, checks if there are potions, then the user choses
                                                                        // potion, each type of potion that is chosen is doing a different
    if (myHero->inv.is_potion_list_empty() == true)                     // thing
    {
        cout << "Potion list is empty!" << endl;
    }
    else
    {
        int pchoice;
        myHero->inv.print_potions();
        cout << "Please input the number of the potion to use: ";
        cin >> pchoice;
        cout << endl;
        while (pchoice < 1 || pchoice > myHero->inv.get_potion_list_size())
        {
            cout << "Bad input!\nPlease choose again:" << endl;
            cin >> pchoice;
        }

            pchoice--;
            if (myHero->inv.get_potion_type(pchoice) == "Health")       // A Health potion restores Hero's health through restore_health(and
            {                                                           // get_potion_power
                myHero->restore_health(myHero->inv.get_potion_power(pchoice));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Magic")   // A Magic potion restores Hero's magic power through restore_magicpower
            {
                myHero->restore_magicpower(myHero->inv.get_potion_power(pchoice));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Damage")  // A Damage potion adds a Damage Buff for 10 turns through add_buff
            {
                myHero->buffs.add_dmgbuff(myHero->inv.get_potion_power(pchoice), 10);
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Defence") // A Defence potion adds a Defence Buff for 10 turns the same way
            {
                myHero->buffs.add_defbuff(myHero->inv.get_potion_power(pchoice), 10);
            }
            else                                                        // An Agility potion adds an agility Buff for 10 turns the same way
            {
                myHero->buffs.add_agibuff(myHero->inv.get_potion_power(pchoice), 10);
            }

            doneTurn = true;                                            // in the end doneTurn is set to true and the potion is removed from the
            myHero->inv.remove_potion(pchoice + 1);                     // inventory
	}

    return doneTurn;                                                    // the doneTurn is returned
}

/* Function for the aftermath of the war
 * has extra arguments the XP and Money that will be gained */
void CommonSquare::afterBattle(Hero** myHeroes, bool heroesWon, int winXp, int winMoney)
{
    if(heroesWon == true)               // if the heroes won the battle
    {
        for(int i = 0; i < 3; i++)      // for each Hero if he exists we add Money and XP through addMoney and addExperience the winXp and winMoney
        {
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->addMoney(winMoney);
                myHeroes[i]->addExperience(winXp);
            }
        }
    }
    else                                // if the heroes lost the battle
    {
        for(int i = 0; i < 3; i++)      // for each Hero if he exists we reduce half its money through subMoney and restore half his
        {                               // health through restore_health
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->subMoney(myHeroes[i]->get_money()/2);
                myHeroes[i]->restore_health(myHeroes[i]->get_health()/2);
            }
        }
    }

    for(int i = 0; i < 3; i++)          // then for each Hero we check if he has to level up through check_levelup function
    {
        if(myHeroes[i] != NULL)
            myHeroes[i]->check_levelup();
    }
}

/* Function to gain the Experience xp from the battle */
int CommonSquare::get_xp(Monster* Monsters[4])
{                                       // for each Monster the XP gained is the monster's level * 200
    int xp=0;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (Monsters[i] != NULL)
		{                               // XP += MonstersLevel * 200
			xp = xp + Monsters[i]->get_level() * 200;
		}
	}
	return xp;
}

/* Function to gain the Money from the battle */
int CommonSquare::get_money(Monster* Monsters[4])
{                                       // same as get_xp
    int money=0;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (Monsters[i] != NULL)
		{                               // Money += MonsterLevel * 75
			money += Monsters[i]->get_level() * 75;
		}
	}
	return money;
}

/* Function to check if the heroes are all fainted */
bool CommonSquare::heroes_all_dead(Hero* Heroes[3])
{                                       // false is returned if the Heroes exits and has no health
    for (int i = 0; i < 3; i++)
	{
		if (Heroes[i] != NULL && Heroes[i]->get_chealth() !=0)
		{
			return false;
		}
	}
	return true;                        // else true is returned
}

/* Function to check if the Monsters are all dead
 * returns true if they are dead */
bool CommonSquare::monsters_all_dead(Monster* Monsters[4])
{                                       // same as the heroes_all_dead except we only check if the Monster exists(because if it has no health
    for (int i = 0; i < 4; i++)         // it will have been deleted)
	{
		if (Monsters[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

/* Function to update the Buffs of the Heroes and Monsters in each round */
void CommonSquare::update_buffs(Hero** Heroes, Monster* Monsters[4])
{
    for (int i = 0; i < 3; i++)             // for the heroes and the monsters it moves the turns through move_buffs and checks the buffs through
	{                                       // check_buffs
		if (Heroes[i] != NULL)
		{
			Heroes[i]->buffs.move_buffs();
			Heroes[i]->buffs.check_buffs();
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (Monsters[i] != NULL)
		{
			Monsters[i]->buffs.move_buffs();
			Monsters[i]->buffs.check_buffs();
		}
	}
	//cout << "Buffs updated" << endl;
}

