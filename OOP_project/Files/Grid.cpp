#include "Grid.h"
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "Square.h"
#include "CommonSquare.h"
#include "MarketSquare.h"
#include "nonAccessibleSquare.h"

using namespace std;

/* Class Ctor */
Grid::Grid(int x, int y): dimensionX(x), dimensionY(y)
{
    int r;

    //srand(time(NULL));

    grid = new Square**[y];
    for(int i = 0; i < y; ++i)
        grid[i] = new Square*[x];

    r = rand() % 3;                             // this is in order the first square not be a non-Accessible
    if(r == 0)
        grid[0][0] = new MarketSquare(0, 0);
    else
        grid[0][0] = new CommonSquare(0, 0);

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
        {
            if(i != 0 || j != 0)
            {
                r = rand()%100;
                if( r > COMMON_SQUARE_POSSIBILITY)
                    grid[i][j] = new CommonSquare(i, j);
                else if( r > MARKET_SQUARE_POSSIBILITY)
                    grid[i][j] = new MarketSquare(i, j);
                else
                    grid[i][j] = new nonAccessibleSquare(i, j);
            }
        }

    currentPosition = grid[0][0];
}

/* Class Dtor */
Grid::~Grid()
{
    for(int i = 0; i < dimensionX; i++)
        for(int j = 0; j < dimensionY; j++)
            delete grid[i][j];

    for(int i = 0; i < dimensionY; ++i)
        delete[] grid[i];

    delete[] grid;
}

/* Getter for the X dimension of the grid */
int Grid::getDimX()
{
    return dimensionX;
}

/* Getter for the Y dimension of the grid */
int Grid::getDimY()
{
    return dimensionY;
}

/* Function to move the hero onto the Grid */
bool Grid::moveGrid()
{
    bool didItMove = false;         // Loukas - variable to return whether the Hero moved or not in the grid
    char direction;
    cout << "Please choose the direction:\n(w: Up, a: Left, s: Down, d: Right)" << endl;
    cin >> direction;
    while(direction != 'w' && direction != 'a' && direction != 's' && direction != 'd')
    {
        cout << "Wrong Input\nPlease Choose again the direction:\n(Only Lower Case Letters)" << endl;
        cin >> direction;
    }

    switch(direction)
    {
        case 'a':
            if(currentPosition->getY() != 0)
            {
                if(grid[currentPosition->getX()][currentPosition->getY() - 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setY(currentPosition->getY() - 1);
                    currentPosition = grid[currentPosition->getX()][currentPosition->getY()];
                    didItMove = true;
                }
                else
                {
                    cout << "You can't move to the left because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move left because you're at the left edge of the map" << endl;
            }

            break;

        case 'w':
            if(currentPosition->getX() != 0)
            {
                if(grid[currentPosition->getX() - 1][currentPosition->getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setX(currentPosition->getX() - 1);
                    currentPosition = grid[currentPosition->getX()][currentPosition->getY()];
                    didItMove = true;
                }
                else
                {
                    cout << "You can't move forward because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move forward because you're at the top of the map" << endl;
            }

            break;

        case 'd':
            if(currentPosition->getY() != (dimensionY - 1))
            {
                if(grid[currentPosition->getX()][currentPosition->getY() + 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setY(currentPosition->getY() + 1);
                    currentPosition = grid[currentPosition->getX()][currentPosition->getY()];
                    didItMove = true;
                }
                else
                {
                    cout << "You can't move to the right because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move to the right because you're at the right edge of the map" << endl;
            }

            break;

        case 's':
            if(currentPosition->getX() != (dimensionX - 1))
            {
                if(grid[currentPosition->getX() + 1][currentPosition->getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setX(currentPosition->getX() + 1);
                    currentPosition = grid[currentPosition->getX()][currentPosition->getY()];
                    didItMove = true;
                }
                else
                {
                    cout << "You can't move backward because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move backward because you're at the bottom of the map" << endl;
            }

            break;
    }

    return didItMove;

}

/* Function displayMap which will show a map of the grid to the user about market, n-accessible and common
   squares and the location of the hero */
   void Grid::displayMap()
   {
       string squareType;
       int squareNo = 1;

       for(int i = 0; i < dimensionX; i++)
       {
            for(int j = 0 ; j < dimensionY; j++)
            {
                if(grid[i][j]->getSquareType() == SQUARE_TYPE_COMMON)
                    squareType = "C ";
                else if(grid[i][j]->getSquareType() == SQUARE_TYPE_MARKET)
                    squareType = "M ";
                else if(grid[i][j]->getSquareType() == SQUARE_TYPE_NON_ACCESSIBLE)
                    squareType = "N-A ";
                else
                    exit(1);

                if(currentPosition->getX() == i && currentPosition->getY() == j)
                    squareType += "H";

                cout << squareNo++ << squareType << "\t\t";

                squareType = "";
            }

            cout << endl << endl;
       }

       cout << "--------------------------------------------" << endl;
       cout << "\t\tMAP" << endl << "H: Hero is here" << endl << "M: This is a Market Square" << endl << "N-A: This is a Non Accessible Square" << endl
            <<"C: This is a Common Square" << endl << endl;
   }

/* Function to call current position's displayMenu through the grid */
void Grid::displayMenu(Hero** myHeroes)
{
    currentPosition->displayMenu(myHeroes);
}

