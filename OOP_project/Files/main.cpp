#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Item.h"
#include "Spell.h"
#include "Grid.h"
#include "MarketSquare.h"
#include "Market.h"
#include "CommonSquare.h"
#include "nonAccessibleSquare.h"
#include "Inventory.h"
#include "Buff.h"
#include "Buff_list.h"
#include "Square.h"
#include "Living.h"

bool play(Grid*, Hero**);               // play, showPlayOptions and endGame declarations
void showPlayOptions();
void endGame(Hero**, Grid*);

using namespace std;

int main(void)
{
    srand(time(NULL));                                  // start of the random numbers' generator

    int heroesNumber;                                   // variable
    int r;
    string name;
    bool endGame = false;
    Hero* myHeroes[3] = {NULL, NULL, NULL};

    cout << "\tWelcome to our Game\n\nPlease choose how many Heroes you want (One to Three):" << endl;
	cin >> heroesNumber;
	while(heroesNumber > 3 || heroesNumber < 1)
    {
        cout << "Wrong  Input\nPlease choose between one and three:" << endl;
        cin >> heroesNumber;
    }

    ifstream inFile;
    inFile.open("items.txt");
    Market* myMarket = MarketSquare::getMarket(inFile);
    inFile.close();

    inFile.open("heroesNames.txt");

    for(int i = 0; i < heroesNumber; i++)
    {
        r = rand()%3;
        if(r == 0)
        {
            inFile >> name;
            myHeroes[i] = new Paladin(name);
        }
        else if(r == 1)
        {
            inFile >> name;
            myHeroes[i] = new Sorcerer(name);
        }
        else if(r == 2)
        {
            inFile >> name;
            myHeroes[i] = new Warrior(name);
        }
    }

    inFile.close();

    Grid* myGrid = new Grid(5, 5);

    while(endGame == false)
    {
        endGame = play(myGrid, myHeroes);
    }

	return 0;
}
/* Function that will run the playtime of the game
 * It has a Hero** and Grid* arguments and returns a boolean value */
bool play(Grid* myGrid, Hero** myHeroes)
{
    bool didItMove;                                 // bool variable to check if the moveGrid actually moved the heroes
    bool quitGame = false;                          // bool variable to check if the user chose to end the game, set firstly to false
    int option;                                     // variable for reading the user option
    showPlayOptions();                              // we show him the available options through the showPlayOptions function and then read
    cin >> option;                                  // his choice

    while(option > 4 || option < 1)                 // check if the option the user chose is valid and force him to choose a right one if not
    {
        cout << "Wrong Choice\nPlease choose again:" << endl;
        cin >> option;
    }

    if(option == 1)                                 // the first option is to move the heroes on to the grid through the moveGrid function that
    {                                               // also returns the bool value to didItMove to check if they moved
        didItMove = myGrid->moveGrid();
        if(didItMove == true)                       // if the hero actually moved and didnt stay in the same square we call the displayMenu of the
            myGrid->displayMenu(myHeroes);          // current square through the displayMenu of the Grid
    }
    else if(option == 2)                            // the second option is to show the Map of the grid through the displayMap function
    {
        myGrid->displayMap();
    }
    else if(option == 3)                            // the third option is to show for each Hero his statistics
    {                                               // we check firstly if there is a Hero(and isnt NULL) and then call his print_stats
        for(int i = 0; i < 3; i++)
        {
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->print_stats();
            }
        }
    }
    else if(option == 4)                            // the fourth choice is to end the game through the endGame function which deletes
    {                                               // the pointers etc. Also the quitGame variable becomes true so that the main "knows"
        endGame(myHeroes, myGrid);                  // the program has to end
        quitGame = true;
    }
    return quitGame;                                // finally we return the quitGame
}

/* Function to show the Options at the first and basic Menu of the game */
void showPlayOptions()
{
    cout << "\n Please choose your option:" << endl;        // The options are:
    cout << " Move on Grid (Press 1)" << endl;              // move on to the grid: moveGrid
    cout << " See the Map (Press 2)" << endl;               // show the map: displayMap
    cout << " Show Hero's Information (Press 3)" << endl;   // show heroes info: print_stats
    cout << " Quit Game (Press 4)" << endl << endl;         // quit the game: endGame
}

/* Function to end the game in the main
 * it has a Hero** and Grid* arguments */
void endGame(Hero** myHeroes, Grid* myGrid)
{
    for(int i = 0; i < 3; i++)                  // for each hero we delete the pointer to him
    {
        delete myHeroes[i];
    }
    delete myHeroes;                            // and then the array of these pointers
    delete myGrid;                              // then the pointer of the grid

    cout << "\n\n\t END GAME" << endl;          // and in the end we print relevant message

}
