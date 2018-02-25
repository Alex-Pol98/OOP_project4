#include <cstdlib>
#include "CommonSquare.h"
#include "Square.h"
#include "Grid.h"
#include "Buff.h"
#include "Buff_list.h"

CommonSquare::CommonSquare(int givenX, int givenY):  Square(SQUARE_TYPE_COMMON, givenX, givenY)
{}

CommonSquare::~CommonSquare()
{}

/* Function for when the user is on a Common Square */
void CommonSquare::displayMenu(Hero** myHeroes)
{
    // There are two options: Battle or ShowMenu depending on the outcome of the rand and the BATTLE_POSSIBILITY
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
	fill_monsters(Monsters,lvl);  //Spawns the monsters.
	winExp = get_xp(Monsters);
	winMoney = get_money(Monsters);

	while(!heroes_all_dead(myHeroes) && !monsters_all_dead(Monsters))
    {
        battleHerosTurn(myHeroes, Monsters);
        battleMonstersTurn(myHeroes, Monsters);
        herosRestore(myHeroes);
    }

    if(monsters_all_dead(Monsters))
    {
        heroesWon = true;
        cout << "\n\tHeroes Won!!" << endl << endl;
    }
    else
    {
        heroesWon = false;
        cout << "\n\tMonsters Won.." << endl << endl;
    }

    afterBattle(myHeroes, heroesWon, winExp, winMoney);
}

/* Function for the Heroes' turn in the battle */
void CommonSquare::battleHerosTurn(Hero** myHeroes, Monster* Monsters[4])
{
    cout << "Heroes' Turn!" << endl;
    int option;
    bool doneTurn;

    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL && myHeroes[i]->get_chealth() > 0 && !monsters_all_dead(Monsters))   
        {
            doneTurn = false;
            while(doneTurn == false)
            {
                cout << "\tHero " << i << " Options:" << endl;                                          
                showBattleOptions();
                cin >> option;

                while(option != 1 && option != 2 && option != 3 &&
                      option != 4 && option != 5)
                {
                    cout << "Wrong Option\n";
                    showBattleOptions();
                    cin >> option;
                }

                if(option == 1)
                    doneTurn = attack(myHeroes[i], Monsters);
                else if(option == 2)
                    doneTurn = castSpell(Monsters, myHeroes[i]);
                else if(option == 3)
                    doneTurn = use(myHeroes[i]);
                else if(option == 4)
                    myHeroes[i]->equip_weapon();
                else if(option == 5)
                    myHeroes[i]->equip_armor();
            }

            update_buffs(myHeroes, Monsters);
        }
    }
}

/* Function for Hero's Restore after each round */
void CommonSquare::herosRestore(Hero** myHeroes)        
{
    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)
        {
            if(myHeroes[i]->get_chealth() != 0)
            {
                myHeroes[i]->restore_health(10);
                myHeroes[i]->restore_magicpower(10);
                myHeroes[i]->print_stats();
            }
        }
    }
}

/* Function for the Monsters' turn in the battle */
void CommonSquare::battleMonstersTurn(Hero* myHeroes[3], Monster* Monsters[4])
{
    if(!heroes_all_dead(myHeroes))
    {
        cout << "Monsters' Turn!" << endl;
        for (int i = 0; i < 4; i++)
        {
            if(!heroes_all_dead(myHeroes))
            {
                int h_att;
                if (Monsters[i] != NULL)
                {
                    cout << "The #" << i << " monster is attacking!" << endl;
                    h_att = rand() % 3;
                    while (myHeroes[h_att] == NULL || myHeroes[h_att]->get_chealth() == 0)
                    {
                        h_att = rand() % 3;
                    }
                    cout << "A Monster will attack the #" << h_att << " Hero!" << endl;
                    myHeroes[h_att]->receive_damage(Monsters[i]->get_damage()*Monsters[i]->buffs.get_all_dmg());
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
    int option = 0;

    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)
        {
            cout << "\tHero " << i << " Options:" << endl;
            while(option != 6)
            {
                showNoBattleOptions();
                cin >> option;

                while(option != 1 && option != 2 && option != 3 &&
                      option != 4 && option != 5 && option != 6)
                {
                    cout << "Wrong Option\n";
                    showNoBattleOptions();
                    cin >> option;
                }

                if(option == 1)
                    myHeroes[i]->inv.print_all();
                else if(option == 2)
                    myHeroes[i]->equip_weapon();
                else if(option == 3)
                    myHeroes[i]->equip_armor();
                else if(option == 4)
                    use(myHeroes[i]);
                else if(option == 5)
                    myHeroes[i]->print_stats();
                else if(option == 6)
                {

                }
            }

            option = 0;
        }
    }
}

/* Function to show a menu to the user to choose what to do in the common square if not battle happens */
void CommonSquare::showNoBattleOptions()
{
    cout << "\n Please choose your option:" << endl;
    cout << " Check your Inventory (Press 1)" << endl;
    cout << " Change Equipped Weapon (Press 2)" << endl;
    cout << " Change Equipped Armor (Press 3)" << endl;
    cout << " Use a Potion (Press 4)" << endl;
    cout << " Show Hero's Information (Press 5)" << endl;
    cout << " Continue your journey (Press 6)" << endl << endl;
}

/* Function to show a menu to the user to choose what to do in the battle */
void CommonSquare::showBattleOptions()
{
    cout << "\nPlease choose your option:" << endl;
    cout << "Attack (Press 1)" << endl;
    cout << "Cast Spell (Press 2)" << endl;
    cout << "Use a Potion (Press 3)" << endl;
    cout << "Change Equipped Weapon (Press 4)" << endl;
    cout << "Change Equipped Armor (Press 5)" << endl << endl;
}
/* Function to create the monsters in the battle */
void CommonSquare::fill_monsters(Monster* Monsters[4],int lvl)
{
    int counter = 0;    
	int tmp;
	tmp = rand() % 3;
	if (tmp == 0)
	{
		Monsters[0] = new Dragon(lvl + rand() % 3 - 1);  //Each monster can be a level higher, the same or a level lower than the heroes.
		counter++;
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
	}
	cout << counter << " Monsters spawned" << endl;     
}

/* Function to print out what monsters exist in the battle field for the user to choose where to attack */
void CommonSquare::print_monsters_in_battle(Monster* monsters[4])
{
	cout << "\tMONSTERS IN BATTLE: { ";
	for (int i = 0; i < 4; i++)
	{
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
	for (int i = 0; i < 4; i++)
	{
		if (monsters[i] != NULL)
		{
			cout <<"#"<< i << "-Monster's data:" << endl;
			monsters[i]->print_data();
		}
	}
}

/* Function for the Heroes to attack the monsters in the battle function */
bool CommonSquare::attack(Hero* myHero, Monster* Monsters[4])
{
    int damage;
    int mchoice;
    int doneTurn = false;
    if(myHero->getEquippedWeapon() != NULL)
    {                                                   
        damage = (myHero->getEquippedWeapon()->get_damage() + myHero->get_strength()/4)*myHero->buffs.get_all_dmg();
    }
    else
    {
        damage = (myHero->get_strength()/4)*myHero->buffs.get_all_dmg();
    }
    print_monsters_in_battle(Monsters);
    cout << "Select the monster you want to attack: " << endl;
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
        cout << "Monster Remaining Health = " << Monsters[mchoice]->get_c_health() << endl;
    }

    return doneTurn;
}

/* Function for the heroes to cast a spell to the monsters in the battle function */
bool CommonSquare::castSpell(Monster* Monsters[4], Hero* myHero)
{
    bool doneTurn = false;

    if (myHero->inv.is_spell_list_empty() == true)
    {
        cout << "The spell list is empty!" << endl;
    }
    else
    {
        int schoice;
        myHero->inv.print_spells();
        cout << "Please input the number of the spell to use: " << endl;
        cin >> schoice;
        cout << endl;
        while (schoice > myHero->inv.get_spell_list_size() || schoice < 1)
        {
            cout << "Bad input!\nPlease choose again:" << endl;
            cin >> schoice;
        }

        {
            schoice--;
            if (myHero->inv.get_spell_manareq(schoice) > myHero->get_magicpower())
            {
                cout << "Not enough Mana to cast the spell!" << endl;
            }
            else
            {
                int damage;
                int mchoice;
                myHero->sub_magicpower(myHero->inv.get_spell_manareq(schoice));
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

    return doneTurn;
}

/* Function for the hero to use potion in the battle function */
bool CommonSquare::use(Hero* myHero)
{
    bool doneTurn = false;

    if (myHero->inv.is_potion_list_empty() == true)
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
            if (myHero->inv.get_potion_type(pchoice) == "Health")
            {
                myHero->restore_health(myHero->inv.get_potion_power(pchoice));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Magic")
            {
                myHero->restore_magicpower(myHero->inv.get_potion_power(pchoice));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Damage")
            {
                myHero->buffs.add_dmgbuff(myHero->inv.get_potion_power(pchoice), 10);
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Defence")
            {
                myHero->buffs.add_defbuff(myHero->inv.get_potion_power(pchoice), 10);
            }
            else
            {
                myHero->buffs.add_agibuff(myHero->inv.get_potion_power(pchoice), 10);
            }

            doneTurn = true;
            myHero->inv.remove_potion(pchoice + 1);    
	}

    return doneTurn;
}

/* Function for the aftermath of the war */
void CommonSquare::afterBattle(Hero** myHeroes, bool heroesWon, int winXp, int winMoney)
{
    if(heroesWon == true)       // if the heroes won the battle
    {
        for(int i = 0; i < 3; i++)
        {
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->addMoney(winMoney);
                myHeroes[i]->addExperience(winXp);
            }
        }
    }
    else                        // if the heroes lost the battle
    {
        for(int i = 0; i < 3; i++)
        {
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->subMoney(myHeroes[i]->get_money()/2);
                myHeroes[i]->restore_health(myHeroes[i]->get_health()/2);
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)
            myHeroes[i]->check_levelup();
    }
}

/* Function to gain the Experience xp from the battle */
int CommonSquare::get_xp(Monster* Monsters[4])
{
    int xp=0;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (Monsters[i] != NULL)
		{
			xp = xp + Monsters[i]->get_level() * 200;
		}
	}
	return xp;
}

/* Function to gain the Money from the battle */
int CommonSquare::get_money(Monster* Monsters[4])
{
    int money=0;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (Monsters[i] != NULL)
		{
			money += Monsters[i]->get_level() * 75;
		}
	}
	return money;
}

/* Function to check if the heroes are all fainted */
bool CommonSquare::heroes_all_dead(Hero* Heroes[3])
{
    for (int i = 0; i < 3; i++)
	{
		if (Heroes[i] != NULL && Heroes[i]->get_chealth() !=0)
		{
			return false;
		}
	}
	return true;
}

/* Function to check if the Monsters are all dead
 * returns true if they are dead */
bool CommonSquare::monsters_all_dead(Monster* Monsters[4])
{
    for (int i = 0; i < 4; i++)
	{
		if (Monsters[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

/* Function to update the Buffs of the Heroes and Monsters in each round
 * returns true if they are dead */
void CommonSquare::update_buffs(Hero** Heroes, Monster* Monsters[4])
{
    for (int i = 0; i < 3; i++)
	{
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
	cout << "Buffs updated" << endl;
}

