#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Inventory.h"
#include "Spell.h"
#include "Living.h"
#include "Buff.h"
#include "Buff_list.h"
#include "Batlle.h"


using namespace std;

int get_xp(Monster* Monsters[4])
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

bool all_dead(Hero* Heroes[3])
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

bool all_dead(Monster* Monsters[4])
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

void update_buffs(Hero* Heroes[3],Monster* Monsters[4])
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

void print_monsters_position(Monster* monsters[4])
{
	cout << "MONSTER POSITIONS: { ";
	for (int i = 0; i < 4; i++)
	{
		if (monsters[i] != NULL)
		{
			cout << i << " ";
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

void print_fightmenu(int no)
{
	cout << "Hero " << no << " chose your action: " << endl;
	cout << "(1) Attack a monster." << endl;
	cout << "(2) Use a spell." << endl;
	cout << "(3) Use a potion." << endl;
	cout << "(4) Change weapon." << endl;
	cout << "(5) Change armor." << endl << endl;
	cout << "INPUT CHOICE: ";
}

void Fill_monsters(Monster* Monsters[4],int lvl)
{
	int tmp;
	tmp = rand() % 3;
	if (tmp == 0)
	{
		Monsters[0] = new Dragon(lvl + rand() % 3 - 1);
	}
	else if (tmp == 1)
	{
		Monsters[0] = new Exoskeleton(lvl + rand() % 3 - 1);
	}
	else
	{
		Monsters[0] = new Spirit(lvl + rand() % 3 - 1);
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
			}
			else if (tmp == 1)
			{
				Monsters[i] = new Exoskeleton(lvl + rand() % 3 - 1);
			}
			else
			{
				Monsters[i] = new Spirit(lvl + rand() % 3 - 1);
			}
		}
	}
	cout << "Monsters spawned" << endl;
}

void battle_procedure(Hero* Heroes[3])
{
	srand(time(NULL));
	bool flag=0;
	int choice;
	int ct = 0;
	int exp_sum;

	Monster* Monsters[4];
	int lvl = Heroes[0]->get_level();
	Fill_monsters(Monsters,lvl);
	exp_sum = get_xp(Monsters);

	while (flag == 0)
	{
		cout << "{ Heroes turn }" << endl;
		for (int i = 0; i < 3; i++)
		{
			if (Heroes[i] != NULL && Heroes[i]->get_chealth()!=0) //If hero exists and is not dead
			{
				print_fightmenu(i);
				cin >> choice;
				switch (choice)
				{
				case 1: //Attack a monster
					int damage, mchoice;
					damage = (Heroes[i]->getEquippedWeapon()->get_damage() + Heroes[i]->get_strength() / 4)*Heroes[i]->buffs.get_all_dmg();
					print_monsters_position(Monsters);
					cout << "Select the monster position to attack: ";
					cin >> mchoice;
					cout << endl;
					if (mchoice > 3 || Monsters[mchoice] == NULL)
					{
						cout << "Bad input!" << endl;
						break;
					}
					Monsters[mchoice]->receive_damage(damage);
					if (Monsters[mchoice]->get_c_health() == 0)
					{
						delete Monsters[mchoice];
						Monsters[mchoice] = NULL;
					}
					else
					{
						cout << "Monster remaining health= " << Monsters[mchoice]->get_c_health() << endl;
					}
					break;
				case 2: //Use a spell
					if (Heroes[i]->inv.is_spell_list_empty() == true)
					{
						cout << "The spell list is empty!" << endl;
					}
					else
					{
						int schoice;
						Heroes[i]->inv.print_spells();
						cout << "Input the number of the spell to use: ";
						cin >> schoice;
						cout << endl;
						if (schoice > Heroes[i]->inv.get_spell_list_size() || schoice < 1)
						{
							cout << "Bad input!" << endl;
						}
						else
						{
							schoice--;
							if (Heroes[i]->inv.get_spell_manareq(schoice) > Heroes[i]->get_cmagicpower())
							{
								cout << "Not enough mana!" << endl;
							}
							else
							{
								int damage, mchoice;
								Heroes[i]->sub_magicpower(Heroes[i]->inv.get_spell_manareq(schoice));
								damage = (Heroes[i]->inv.get_spell_damage(schoice) + (Heroes[i]->get_dexterity() / 3))*Heroes[i]->buffs.get_all_dmg();
								print_monsters_position(Monsters);
								cout << "Select the monster position to use the spell: ";
								cin >> mchoice;
								cout << endl;
								if (mchoice > 3 || Monsters[mchoice] == NULL)
								{
									cout << "Bad input!" << endl;
									break;
								}
								Monsters[mchoice]->receive_damage(damage);
								if (Monsters[mchoice]->get_c_health() == 0)
								{
									delete Monsters[mchoice];
									Monsters[mchoice] = NULL;
								}
								else
								{
									if (Heroes[i]->inv.get_spell_type(schoice) == "Fire")
									{
										Monsters[mchoice]->buffs.add_dmgbuff(-5, 3);
									}
									else if (Heroes[i]->inv.get_spell_type(schoice) == "Ice")
									{
										Monsters[mchoice]->buffs.add_defbuff(-5, 3);
									}
									else
									{
										Monsters[mchoice]->buffs.add_agibuff(-5, 3);
									}
								}
							}
						}
					}
					break;
				case 3:
					if (Heroes[i]->inv.is_potion_list_empty() == true)
					{
						cout << "Potion list is empty!" << endl;
					}
					else
					{
						int pchoice;
						Heroes[i]->inv.print_potions();
						cout << "Input the number of the potion to use: ";
						cin >> pchoice;
						cout << endl;
						if (pchoice < 1 || pchoice > Heroes[i]->inv.get_potion_list_size())
						{
							cout << "Bad input!" << endl;
							break;
						}
						else
						{
							pchoice--;
							if (Heroes[i]->inv.get_potion_type(pchoice) == "Health")
							{
								Heroes[i]->restore_health(Heroes[i]->inv.get_potion_power(i));
							}
							else if (Heroes[i]->inv.get_potion_type(pchoice) == "Magic")
							{
								Heroes[i]->restore_magicpower(Heroes[i]->inv.get_potion_power(i));
							}
							else if (Heroes[i]->inv.get_potion_type(pchoice) == "Damage")
							{
								Heroes[i]->buffs.add_dmgbuff(Heroes[i]->inv.get_potion_power(pchoice), 3);
							}
							else if (Heroes[i]->inv.get_potion_type(pchoice) == "Defence")
							{
								Heroes[i]->buffs.add_defbuff(Heroes[i]->inv.get_potion_power(pchoice), 3);
							}
							else
							{
								Heroes[i]->buffs.add_agibuff(Heroes[i]->inv.get_potion_power(pchoice), 3);
							}
						}
					}
				case 4:
					//equip weapon
				case 5:
					//equip armor
				default:
					cout << "Bad input losing turn" << endl;
					break;
				}
				update_buffs(Heroes, Monsters);
			}
			cout << endl;
		}
		cout << endl;
		if (all_dead(Monsters) == true)
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "{ Monster's turn }" << endl;
			for (int i = 0; i < 4; i++)
			{
				int h_att;
				if (Monsters[i] != NULL)
				{
					cout << "The #" << i << " monster is attacking!" << endl;
					h_att = rand() % 3;
					while (Heroes[h_att] == NULL || Heroes[h_att]->get_chealth() == 0)
					{
						h_att = rand() % 3;
					}
					cout << "A Monster will attack the #" << h_att + 1 << " Hero!" << endl;
					Heroes[h_att]->receive_damage(Monsters[i]->get_damage()*Monsters[i]->buffs.get_all_dmg());
					cout << "Health remaining= " << Heroes[h_att]->get_chealth() << endl;
					update_buffs(Heroes, Monsters);
					if (all_dead(Heroes) == true)
					{
						cout << "GAME OVER";
						assert(false);
					}
				}
			}
		}
		if (all_dead(Heroes) == true)
		{
			cout << "GAME OVER";
			assert(false);
		}
	}
	cout << "BATTLE WON!" << endl;
}

