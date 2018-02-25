#include "MarketSquare.h"
#include "Market.h"
#include "Square.h"
#include <iostream>

using namespace std;

/*Ctor of the class MarketSquare*/
MarketSquare::MarketSquare(int givenX, int givenY):Square(SQUARE_TYPE_MARKET, givenX, givenY)         // it calls the Square's class ctor with argument the constant SQUARE_TYPE_MARKET
{}                                                              // which is defined in the square.h

MarketSquare::~MarketSquare(){}

Market* MarketSquare::market = NULL;

/* Function for the static Market of the Squares to be initialised */
Market* MarketSquare::getMarket(ifstream &inFile)
{
    if(market == NULL)
    {
        market = new Market(inFile);
    }

    return market;
}


/*
 * Function to show the menu of the Market when the player is accessing a square market
 */
void MarketSquare::displayMenu(Hero** myHeroes)
{
    int option = -1;

    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)
        {
            cout << "Welcome to the market Hero " << i << ". How can we help you?" << endl;

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
                        buy(myHeroes[i]);
                        break;
                    case 2:
                        sell(myHeroes[i]);
                        break;
                    case 3:
                        myHeroes[i]->inv.print_all();
                        break;
                    case 4:
                        break;
                }
            }
            option = -1;
        }
    }
}

/*
 * Function Buy which will be called from the user through marketMenu() if they want to buy sth
 */
 void MarketSquare::buy(Hero* myHero)
 {
    unsigned int optionOne = 0;
    unsigned int optionTwo;

    while(optionOne != 5)
    {
        showBuyOptions();
        cin >> optionOne;

        while(optionOne != 1 && optionOne != 2 && optionOne != 3 && optionOne != 4 && optionOne != 5)
        {
            cout << "Wrong Choice\nChoose again:\n";
            showBuyOptions();
            cin >> optionOne;
        }

        if(optionOne == 1)
            market->print_weapons();
        else if(optionOne == 2)
            market->print_spells();
        else if(optionOne == 3)
            market->print_armors();
        else if(optionOne == 4)
            market->print_potions();
        else if(optionOne == 5)
            return;

        cout << "Choose the number of the list that you want" << endl;
        cin >> optionTwo;

        if(optionOne == 1)
        {
            while(optionTwo > market->getWeapons().size() || optionTwo <= 0)
            {
                cout << "Wrong Input\nChoose again the number of the list that you want" << endl;
                cin >> optionTwo;
            }
            if(myHero->get_money() >= market->getWeapons().at(optionTwo - 1).get_price())
            {
               if(myHero->get_level() >= market->getWeapons().at(optionTwo - 1).get_minlvl())
               {
                    myHero->subMoney(market->getWeapons().at(optionTwo - 1).get_price());
                    cout << "Weapon #" << optionTwo << " bought" << endl;
                    myHero->inv.add_weapon(market->getWeapons().at(optionTwo - 1));
               }
               else
                {
                    cout << "Your Hero doesn't have the Level required for this purchase" << endl;
                }
            }
            else
            {
                cout << "Your Hero doesn't have enough money for this purchase" << endl;
            }
        }
        else if(optionOne == 2)
        {
            while(optionTwo > market->getSpells().size() || optionTwo <= 0)
            {
                cout << "Wrong Input\nChoose again the number of the list that you want" << endl;
                cin >> optionTwo;
            }
            if(myHero->get_money() >= market->getSpells().at(optionTwo - 1).get_price())
            {
                if(myHero->get_level() >=  market->getSpells().at(optionTwo - 1).get_minlvl())
                {
                    myHero->subMoney(market->getSpells().at(optionTwo - 1).get_price());
                    cout << "Spell #" << optionTwo << " bought" << endl;
                    myHero->inv.add_spell(market->getSpells().at(optionTwo - 1));
                }
                else
                {
                    cout << "Your Hero doesn't have the Level required for this purchase" << endl;
                }
            }
            else
            {
                cout << "Your Hero doesn't have enough money for this purchase" << endl;
            }
        }

        else if(optionOne == 3)
        {
            while(optionTwo > market->getArmors().size() || optionTwo <= 0)
            {
                cout << "Wrong Input\nChoose again the number of the list that you want" << endl;
                cin >> optionTwo;
            }
            if(myHero->get_money() >= market->getArmors().at(optionTwo - 1).get_price())
            {
                if(myHero->get_level() >= market->getArmors().at(optionTwo - 1).get_minlvl())
                {
                    myHero->subMoney(market->getArmors().at(optionTwo - 1).get_price());
                    cout << "Armor #" << optionTwo << " bought" << endl;
                    myHero->inv.add_armor(market->getArmors().at(optionTwo - 1));
                }
                else
                {
                    cout << "Your Hero doesn't have the Level required for this purchase" << endl;
                }
            }
            else
            {
                cout << "Your Hero doesn't have enough money for this purchase" << endl;
            }
        }

        else if(optionOne == 4)
        {
            while(optionTwo > market->getPotions().size() || optionTwo <= 0)
            {
                cout << "Wrong Input\nChoose again the number of the list that you want" << endl;
                cin >> optionTwo;
            }
            if(myHero->get_money() >= market->getPotions().at(optionTwo - 1).get_price())
            {
                if(myHero->get_level() >= market->getPotions().at(optionTwo - 1).get_minlvl())
                {
                    myHero->subMoney(market->getPotions().at(optionTwo - 1).get_price());
                    cout << "Potion #" << optionTwo << " bought" << endl;
                    myHero->inv.add_potion(market->getPotions().at(optionTwo - 1));
                }
                else
                {
                    cout << "Your Hero doesn't have the Level required for this purchase" << endl;
                }
            }
            else
            {
                cout << "Your Hero doesn't have enough money for this purchase" << endl;
            }
        }
        else if(optionOne == 5)
        {
            return;
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
            myHero->inv.print_all();
        }
        else if(option == 2)
        {
            if(myHero->getEquippedArmor() != NULL)
            {
                myHero->addMoney(myHero->getEquippedArmor()->get_price()/2);
                myHero->tossArmor();
                cout << "Equiped armor sold" << endl;
            }
            else
            {
                cout << "You don't have an equipped Armor" << endl;     // Loukas
            }
        }
        else if(option == 3)
        {
            if(myHero->getEquippedWeapon() != NULL)
            {
                myHero->addMoney(myHero->getEquippedWeapon()->get_price()/2);
                myHero->tossWeapon();
                cout << "Equiped weapon sold" << endl;
            }
            else
            {
                cout << "You don't have an equipped Weapon" << endl;    // Loukas
            }
        }
        else if(option == 4)
        {
            cout << "Type the Spell number you want to sell" << endl;
            cin >> itemNo;

            if (myHero->inv.get_spell_list_size() >= itemNo && itemNo > 0)
            {
                myHero->addMoney(myHero->inv.get_spell_price(itemNo - 1)/ 2);
                myHero->inv.remove_spell(itemNo);
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

            if (myHero->inv.get_weapon_list_size() >= itemNo && itemNo > 0)
            {
                myHero->addMoney(myHero->inv.get_weapon_price(itemNo - 1) / 2);
                myHero->inv.remove_weapon(itemNo);
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

            if (myHero->inv.get_armor_list_size() >= itemNo && itemNo > 0)
            {
                myHero->addMoney(myHero->inv.get_armor_price(itemNo - 1) / 2);
                myHero->inv.remove_armor(itemNo);
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

            if (myHero->inv.get_potion_list_size() >= itemNo && itemNo > 0)
            {
                myHero->addMoney(myHero->inv.get_potion_price(itemNo - 1) / 2);
                myHero->inv.remove_potion(itemNo);
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
    cout << "\n Please choose your option:" << endl;
    cout << " Buy (Press 1)" << endl;
    cout << " Sell (Press 2)" << endl;
    cout << " Show Inventory (Press 3)" << endl;
    cout << " Continue your journey (Press 4)" << endl << endl;
}

void showBuyOptions()
{
        cout << "\n Please choose your option:" << endl;
        cout << " Buy Weapon (Press 1)" << endl;
        cout << " Buy Spell (Press 2)" << endl;
        cout << " Buy Armor (Press 3)" << endl;
        cout << " Buy Potion (Press 4)" << endl;
        cout << " Return to the Market Menu (Press 5)" << endl << endl;
}

void showSellOptions()
{
    cout << "\n Please choose your option:" << endl;
    cout << " Check your inventory (Press 1)" << endl;
    cout << " Sell your equipped Armor (Press 2)" << endl;
    cout << " Sell your equipped Weapon (Press 3)" << endl;
    cout << " Sell Spell (Press 4)" << endl;
    cout << " Sell Weapon (Press 5)" << endl;
    cout << " Sell Armor (Press 6)" << endl;
    cout << " Sell Potion (Press 7)" << endl;
    cout << " Return to the Market Menu (Press 8)" << endl << endl;
}



