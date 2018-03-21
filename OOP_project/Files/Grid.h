#ifndef GRID_H
#define GRID_H
#include "Square.h"
#include <string>
#include <iostream>
#include "CommonSquare.h"
#include "MarketSquare.h"
#include "nonAccessibleSquare.h"

using namespace std;

const int COMMON_SQUARE_POSSIBILITY = 40;           // these possibilities are for the Grid Ctor: there is a 60% possibility(100% - 40%)
const int MARKET_SQUARE_POSSIBILITY = 10;           // for a Common Square, 30% for a Market Square(40% - 10%) and 10% for a NonAccessible

class Grid
{
    public:
        Grid(int x, int y);
        ~Grid();
        bool moveGrid();
        int getDimX();
        int getDimY();
        void displayMap();
        void displayMenu(Hero**);
    private:
        Square*** grid;
        Square* currentPosition;
        int dimensionX;
        int dimensionY;
};

#endif // GRID_H
