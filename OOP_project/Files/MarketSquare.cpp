#include "MarketSquare.h"
#include "Market.h"
#include "Square.h"
#include <iostream>

using namespace std;

/*Ctor of the class MarketSquare*/
MarketSquare::MarketSquare(int givenX, int givenY):Square(SQUARE_TYPE_MARKET, givenX, givenY)         // it calls the Square's class ctor with argument the constant SQUARE_TYPE_MARKET
{}                                                              // which is defined in the square.h

MarketSquare::~MarketSquare(){}

/*
 * Function to show the menu of the Market when the player is accessing a square market
 */
void MarketSquare::marketMenu(Hero* myHero)
{
    cout << "Welcome to the Market. How can we help you?" << endl;

    int option = -1;

    while(option != 4)
    {
        showMarketOptions();
        cin >> option;

        while(option != 1 && option != 2 && option != 3 && option != 4)
        {
            cout << "Wrong Option\nChoose Again:";
            showMarketOptions();
            cin >> option;
        }

        switch(option)
        {
            case 1:
                buy(myHero);
                break;
            case 2:
                sell(myHero);
                break;
            case 3:
                myHero->getInventory()->print_all();
                break;
            case 4:
                return;
        }
    }
}

/*
 * Function Buy which will be called from the user through marketMenu() if they want to buy sth
 */
 void MarketSquare::buy(Hero* myHero)
 {
    char optionOne = 'r';
    unsigned int optionTwo;

    while(optionOne != 'e' && optionOne != 'E')
    {
        showBuyOptions();
        cin >> optionOne;

        while(optionOne != 'w' && optionOne != 'W' && optionOne != 's' && optionOne != 'S' && optionOne != 'A' && optionOne != 'a' &&
              optionOne != 'p' && optionOne != 'P' && optionOne != 'r' && optionOne != 'R')
        {
            cout << "Wrong Choice\nChoose again:\n";
            showBuyOptions();
            cin >> optionOne;
        }

        if(optionOne != 'w' || optionOne != 'W')
            market.print_weapons();
        else if(optionOne != 's' || optionOne != 'S')
            market.print_spells();
        else if(optionOne != 'a' || optionOne != 'A')
            market.print_spells();
        else if(optionOne != 'p' || optionOne != 'P')
            market.print_spells();
        else if(optionOne != 'r' || optionOne != 'R' )
            return;
        cout << "Choose the number of the list that you want" << endl;

        cin >> optionTwo;

        if(optionOne != 'w' || optionOne != 'W')
        {
           if(myHero->get_money() >= market.getWeapons().at(optionTwo - 1).get_price())
           {
               myHero->subMoney(market.getWeapons().at(optionTwo - 1).get_price());
               cout << "Weapon #" << optionTwo << " bought" << endl;
               myHero->getInventory()->add_weapon(market.getWeapons().at(optionTwo - 1));
           }
        }
        else if(optionOne != 's' || optionOne != 'S')
        {
            if(myHero->get_money() >= market.getSpells().at(optionTwo - 1).get_price())
            {
                myHero->subMoney(market.getSpells().at(optionTwo - 1).get_price());
                cout << "Spell #" << optionTwo << " bought" << endl;
                myHero->getInventory()->add_spell(market.getSpells().at(optionTwo - 1));
            }
        }

        else if(optionOne != 'a' || optionOne != 'A')
        {
            if(myHero->get_money() >= market.getArmors().at(optionTwo - 1).get_price())
            {
                myHero->subMoney(market.getArmors().at(optionTwo - 1).get_price());
                cout << "Armor #" << optionTwo << " bought" << endl;
                myHero->getInventory()->add_armor(market.getArmors().at(optionTwo - 1));
            }
        }

        else if(optionOne != 'p' || optionOne != 'P')
        {
            if(myHero->get_money() >= market.getPotions().at(optionTwo - 1).get_price())
            {
                myHero->subMoney(market.getPotions().at(optionTwo - 1).get_price());
                cout << "Potion #" << optionTwo << " bought" << endl;
                myHero->getInventory()->add_potion(market.getPotions().at(optionTwo - 1));
            }
        }
    }
 }


 /*
  * Function Sell which will be called from the user through marketMenu() if they want to sell sth
  */
 void MarketSquare::sell(Hero* myHero)
 {
    int option = -1;
    int itemNo = -1;

    while(option != 8)
    {
        showSellOptions();
        cin >> option;

        while(option != 1 && option != 2 && option != 3 && option != 4
               && option != 5 && option != 6 && option != 7 && option != 8)
        {
            cout << "Wrong Option Choice\nChoose again" << endl;
            showSellOptions();
            cin >> option;
        }

        if(option == 1)
        {
            myHero->getInventory()->print_all();
        }
        else if(option == 2)
        {
            myHero->addMoney(myHero->getEquippedArmor()->get_price()/2);
            myHero->tossArmor();
            cout << "Equiped armor sold" << endl;
        }
        else if(option == 3)
        {
            myHero->addMoney(myHero->getEquippedWeapon()->get_price()/2);
            myHero->tossWeapon();
            cout << "Equiped weapon sold" << endl;
        }
        else if(option == 4)
        {
            cout << "Type the Spell number you want to sell" << endl;
            cin >> itemNo;

            if (myHero->getInventory()->spell_list.size() >= itemNo)
            {
                myHero->addMoney(myHero->getInventory()->spell_list[itemNo - 1].get_price() / 2);
                myHero->getInventory()->remove_spell(itemNo);
                cout << "Spell sold" << endl;
            }
            else
            {
                cout << "Error: There is no item with this number" << endl;
            }
        }
        else if(option == 5)
        {
            cout << "Type the Weapon number you want to sell" << endl;
            cin >> itemNo;

            if (myHero->getInventory()->weapon_list.size() >= itemNo)
            {
                myHero->addMoney(myHero->getInventory()->weapon_list[itemNo - 1].get_price() / 2);
                myHero->getInventory()->remove_weapon(itemNo);
                cout << "Weapon sold" << endl;
            }
            else
            {
                cout << "Error: There is no item with this number" << endl;
            }
        }
        else if(option == 6)
        {
            cout << "Type the Armor number you want to sell" << endl;
            cin >> itemNo;

            if (myHero->getInventory()->armor_list.size() >= itemNo)
            {
                myHero->addMoney(myHero->getInventory()->armor_list[itemNo - 1].get_price() / 2);
                myHero->getInventory()->remove_armor(itemNo);
                cout << "Armor sold" << endl;
            }
            else
            {
                cout << "Error: There is no item with this number" << endl;
            }
        }
        else if(option == 7)
        {
            cout << "Type the Potion number you want to sell" << endl;
            cin >> itemNo;

            if (myHero->getInventory()->potion_list.size() >= itemNo)
            {
                myHero->addMoney(myHero->getInventory()->potion_list[itemNo - 1].get_price() / 2);
                myHero->getInventory()->remove_potion(itemNo);
                cout << "Potion sold" << endl;
            }
            else
            {
                cout << "Error: There is no item with this number" << endl;
            }
        }
        else if(option == 8)
            return;

    }
 }


void showMarketOptions()
{
    cout << "Please choose your option:" << endl;
    cout << "Buy (Press 1)" << endl;
    cout << "Sell (Press 2)" << endl;
    cout << "Show Inventory (Press 3)" << endl;
    cout << "Continue your journey (Press 4)" << endl;
}

void showBuyOptions()
{
        cout << "Please choose your option:" << endl;
        cout << "Buy Spell (Press s)" << endl;
        cout << "Buy Weapon (Press w)" << endl;
        cout << "Buy Armor (Press a)" << endl;
        cout << "Buy Potion (Press p)" << endl;
        cout << "Return to the Market Menu (Press r)" << endl;
}

void showSellOptions()
{
    cout << "Please choose your option:" << endl;
    cout << "Check your inventory (Press 1)" << endl;
    cout << "Sell your equipped Armor (Press 2)" << endl;
    cout << "Sell your equipped Weapon (Press 3)" << endl;
    cout << "Sell Spell (Press 4)" << endl;
    cout << "Sell Weapon (Press 5)" << endl;
    cout << "Sell Armor (Press 6)" << endl;
    cout << "Sell Potion (Press 7)" << endl;
    cout << "Return to the Market Menu (Press 8)" << endl;
}



