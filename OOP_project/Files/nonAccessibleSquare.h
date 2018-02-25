#ifndef NONACCESSIBLESQUARE_H
#define NONACCESSIBLESQUARE_H
#include "Square.h"
#include "Living.h"



class nonAccessibleSquare : public Square
{
    public:
        nonAccessibleSquare(int, int);
        ~nonAccessibleSquare();
        void displayMenu(Hero** myHeroes);

};

#endif // NONACCESSIBLESQUARE_H
