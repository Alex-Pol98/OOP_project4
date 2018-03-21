#ifndef COMMONSQUARE_H
#define COMMONSQUARE_H
#include "Square.h"
#include "Living.h"
#include "Buff.h"
#include "Buff_list.h"

const int BATTLE_POSSIBILITY = 50;                              // battlePossibility is 50, if rand returns over 50 we have Battle else noBattle

class CommonSquare: public Square
{
    public:
        CommonSquare(int, int);
        ~CommonSquare();
        void displayMenu(Hero**);
        void showBattleOptions();
        void battle(Hero**);
        void noBattle(Hero**);
        void battleHerosTurn(Hero**, Monster* Monsters[4]);
        void battleMonstersTurn(Hero**, Monster* Monsters[4]);
        void showNoBattleOptions();
        void fill_monsters(Monster* Monsters[4],int);
        void print_monsters_in_battle(Monster* monsters[4]);
        bool attack(Hero*, Monster* monsters[4]);
        bool castSpell(Monster* monsters[4], Hero*);
        bool use(Hero*);
        void afterBattle(Hero**, bool, int, int);
        int get_xp(Monster* Monsters[4]);
        int get_money(Monster* Monsters[4]);
        bool heroes_all_dead(Hero* Heroes[3]);
        bool monsters_all_dead(Monster* Monsters[4]);
        void update_buffs(Hero**, Monster* Monsters[4]);
        void herosRestore(Hero**);
};

#endif // COMMONSQUARE_H
