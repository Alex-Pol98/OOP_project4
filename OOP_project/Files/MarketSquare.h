#ifndef MARKETSQUARE_H
#define MARKETSQUARE_H
#include "Living.h"
#include "Market.h"
#include "Square.h"


class MarketSquare : public Square
{
    public:
        MarketSquare(int, int);
        ~MarketSquare();
        void displayMenu(Hero**);
        void buy(Hero*);
        void sell(Hero*);
        static Market* market;                      // static Market so that all the MarketSquares have the same Market
        static Market* getMarket(ifstream &inFile);
};

void showMarketOptions();
void showBuyOptions();
void showSellOptions();
#endif // MARKETSQUARE_H
