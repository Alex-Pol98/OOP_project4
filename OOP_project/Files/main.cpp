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

bool play(Grid*, Hero**, Market*);                      // play, showPlayOptions and endGame declarations
void showPlayOptions();
void endGame(Hero**, Grid*, Market*);

using namespace std;

int main(void)
{
    srand(time(NULL));                                  // start of the random numbers' generator

    int heroesNumber;                                   // variable for the heroes number
    int r;                                              // int to be used as random number
    string name;                                        // variable for the name of the heroes
    bool endGame = false;                               // bool variable that will be the return value of endGame function to check if the game will end
    Hero* myHeroes[3] = {NULL, NULL, NULL};             // array creation of 3 Null hero pointers

    cout << "\tWelcome to our Game\n\nPlease choose how many Heroes you want (One to Three):" << endl;
	cin >> heroesNumber;                                // welcome message print and read from user the heroes' number along with check about this
	while(heroesNumber > 3 || heroesNumber < 1)         // number(1-3)
    {
        cout << "Wrong  Input\nPlease choose between one and three:" << endl;
        cin >> heroesNumber;
    }

    ifstream inFile;                                    // ifstream creation and items.txt open to read the Market's products from a file
    inFile.open("items.txt");
    Market* myMarket = MarketSquare::getMarket(inFile);
    inFile.close();                                     // close the items.txt file

    inFile.open("heroesNames.txt");                     // open the heroesNames.txt to read the Heroes' names from a file

    for(int i = 0; i < heroesNumber; i++)               // through rand() there are three options: paladin, sorcerer and warrior
    {                                                   // each of them will take a name from the file
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

    inFile.close();                                     // and close the file

    Grid* myGrid = new Grid(5, 5);                      // then we create the Grid with a total of 25 squares

    while(endGame == false)                             // and while the endGame is false(which means that the play function hasnt returned
    {                                                   // a true value from the user) the game is played
        endGame = play(myGrid, myHeroes, myMarket);
    }
                                                        // when we break from the while loop the program returns 0 and ends
	return 0;
}
/* Function that will run the playtime of the game
 * It has a Hero**, Market* and Grid* arguments and returns a boolean value */
bool play(Grid* myGrid, Hero** myHeroes, Market* myMarket)
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
        endGame(myHeroes, myGrid, myMarket);        // the program has to end
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
void endGame(Hero** myHeroes, Grid* myGrid, Market* myMarket)
{
    for(int i = 0; i < 3; i++)                  // for each hero we delete the pointer to him
    {
        delete myHeroes[i];
    }

    delete myGrid;                              // then the pointer of the grid
    delete myMarket;                            // then the pointer of the grid

    cout << "\n\n\t END GAME" << endl;          // and in the end we print relevant message

}
