#include "MarketSquare.h"
#include "Market.h"
#include "Square.h"
#include <iostream>

using namespace std;

/*Ctor of the class MarketSquare*/
MarketSquare::MarketSquare(int givenX, int givenY):Square(SQUARE_TYPE_MARKET, givenX, givenY)
{}                                                              // it calls the Square's class ctor with argument the constant SQUARE_TYPE_MARKET
                                                                // which is defined in the square.h
MarketSquare::~MarketSquare(){}

Market* MarketSquare::market = NULL;                            // The static Market is set to NULL

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
    int option = -1;                                    // The MarketSquare displayMenu for each Hero that exists(not NULL) prints a welcome
                                                        // message, shows him the available options, and reads him choice after forcing him to
    for(int i = 0; i < 3; i++)                          // choose right
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
                        buy(myHeroes[i]);               // the first option is to buy sth from the Market through the Buy function
                        break;
                    case 2:
                        sell(myHeroes[i]);              // the second option is to sell sth from the Inventory through the Sell function
                        break;
                    case 3:
                        myHeroes[i]->inv.print_all();   // the third option is to show the Hero's Inventory Items
                        break;
                    case 4:                             // the fourth option is to return to the main Menu
                        break;
                }
            }
            option = -1;                                // option is reset to -1 for the next Hero in the for loop
        }
    }
}

/*
 * Function Buy which will be called from the user through marketMenu() if they want to buy sth
 */
 void MarketSquare::buy(Hero* myHero)
 {
    unsigned int optionOne = 0;                         // variable for the user to choose <item>
    unsigned int optionTwo;                             // variable for the user to choose an item from the list

    while(optionOne != 5)                               // while the user doesn't want to return to the Market Menu we read the user
    {                                                   // options and force him to choose right
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

        if(optionOne == 1)                              // the first option is to buy weapons
        {
            while(optionTwo > market->getWeapons().size() || optionTwo <= 0)
            {
                cout << "Wrong Input\nChoose again the number of the list that you want" << endl;
                cin >> optionTwo;
            }
                                                        // then we check for each <item> if there is enough Hero's Money and
            if(myHero->get_money() >= market->getWeapons().at(optionTwo - 1).get_price())
            {                                           // the Hero's level > Minimun Level of the <item> and add it to the
               if(myHero->get_level() >= market->getWeapons().at(optionTwo - 1).get_minlvl())
               {                                        // Hero's Inventory
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
        else if(optionOne == 2)                         // the second option is to buy a spell
        {                                               // SAME
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

        else if(optionOne == 3)                         // the third option is to buy an armor
        {                                               // SAME
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

        else if(optionOne == 4)                         // the fourth option is to buy a potion
        {                                               // SAME
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
        else if(optionOne == 5)                         // the fifth option is to return to the Market Menu
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
    int option = -1;                                // same as the buy Function
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

        if(option == 1)                     // the first option is to see the Hero's Inventory through print_all function
        {
            myHero->inv.print_all();
        }
        else if(option == 2)                // the second option is to sell the equipped armor through tossArmor and add the money through
        {                                   // the addMoney and after checking if there is an equipped armor
            if(myHero->getEquippedArmor() != NULL)
            {
                myHero->addMoney(myHero->getEquippedArmor()->get_price()/2);
                myHero->tossArmor();
                cout << "Equiped armor sold" << endl;
            }
            else
            {
                cout << "You don't have an equipped Armor" << endl;
            }
        }
        else if(option == 3)                // the third option is to sell the equipped weapon through tossWeapon and add the money through
        {                                   // the addMoney and after checking if there is an equipped weapon
            if(myHero->getEquippedWeapon() != NULL)
            {
                myHero->addMoney(myHero->getEquippedWeapon()->get_price()/2);
                myHero->tossWeapon();
                cout << "Equiped weapon sold" << endl;
            }
            else
            {
                cout << "You don't have an equipped Weapon" << endl;
            }
        }
        else if(option == 4)                // the fourth option is to sell a spell through remove_spell and addMoney
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
        else if(option == 5)                // the fifth option is to sell a weapon through remove_weapon and addMoney
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
        else if(option == 6)                // the sixth option is to sell an armor through remove_armor and addMoney
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
        else if(option == 7)                // the seventh option is to sell a potion through remove_potion and addMoney
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
        else if(option == 8)                // the eighth option is to return to the Market Menu
            return;

    }
 }

/* Function to show the Market Options, when entering it */
void showMarketOptions()
{
    cout << "\n Please choose your option:" << endl;            // The Options are:
    cout << " Buy (Press 1)" << endl;                           // Buy sth
    cout << " Sell (Press 2)" << endl;                          // Sell sth
    cout << " Show Inventory (Press 3)" << endl;                // See Inventory
    cout << " Continue your journey (Press 4)" << endl << endl; // return to the main Menu
}

/* Function to show the Buy Options */
void showBuyOptions()
{
        cout << "\n Please choose your option:" << endl;                // The Options are:
        cout << " Buy Weapon (Press 1)" << endl;                        // Buy Weapon
        cout << " Buy Spell (Press 2)" << endl;                         // Buy Spell
        cout << " Buy Armor (Press 3)" << endl;                         // Buy Armor
        cout << " Buy Potion (Press 4)" << endl;                        // Buy Potion
        cout << " Return to the Market Menu (Press 5)" << endl << endl; // return to the Market Menu
}

/* Function to show the Sell Option */
void showSellOptions()
{
    cout << "\n Please choose your option:" << endl;                // The Options are:
    cout << " Check your inventory (Press 1)" << endl;              // See your Inventory
    cout << " Sell your equipped Armor (Press 2)" << endl;          // Sell the equipped armor
    cout << " Sell your equipped Weapon (Press 3)" << endl;         // Sell the equipped weapon
    cout << " Sell Spell (Press 4)" << endl;                        // sell spell
    cout << " Sell Weapon (Press 5)" << endl;                       // sell weapon
    cout << " Sell Armor (Press 6)" << endl;                        // sell armor
    cout << " Sell Potion (Press 7)" << endl;                       // sell potion
    cout << " Return to the Market Menu (Press 8)" << endl << endl; // return to the Market Menu
}
