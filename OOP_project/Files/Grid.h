#ifndef GRID_H
#define GRID_H
#include "Square.h"
#include "CommonSquare.h"
#include "MarketSquare.h"
#include "nonAccessibleSquare.h"

const int COMMON_SQUARE_POSSIBILITY = 40;
const int MARKET_SQUARE_POSSIBILITY = 10;

class Grid
{
    public:
        Grid(int x, int y);
        ~Grid();
        void moveGrid(char direction);
        int getDimX();
        int getDimY();
    private:
        Square*** grid;
        Square currentPosition;
        int dimensionX;
        int dimensionY;
};

#endif // GRID_H
