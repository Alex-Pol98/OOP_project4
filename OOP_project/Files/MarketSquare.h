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
        static Market* market;
        static Market* getMarket(ifstream &inFile);
        //Market* market; //Sklavenitis prepei na ginei static gia na exoyn prosbash ola ta square sto idio market alla den kserw pws
};

//Market MarketSquare::market;

void showMarketOptions();
void showBuyOptions();
void showSellOptions();
#endif // MARKETSQUARE_H
