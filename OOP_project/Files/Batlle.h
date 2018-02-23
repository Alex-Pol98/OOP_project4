#pragma once
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

using namespace std;

int get_xp(Monster* Monsters[4]);
bool all_dead(Hero* Heroes[3]);
bool all_dead(Monster* Monsters[4]);
void update_buffs(Hero* Heroes[3], Monster* Monsters[4]);
void print_monsters_position(Monster* monsters[4]);
void print_fightmenu(int no);
void Fill_monsters(Monster* Monsters[4], int lvl);
void battle_procedure(Hero* Heroes[3]);