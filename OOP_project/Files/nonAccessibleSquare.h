#ifndef NONACCESSIBLESQUARE_H
#define NONACCESSIBLESQUARE_H
#include "Square.h"


class nonAccessibleSquare : public Square
{
    public:
        nonAccessibleSquare(int, int);
        ~nonAccessibleSquare();
};

#endif // NONACCESSIBLESQUARE_H
