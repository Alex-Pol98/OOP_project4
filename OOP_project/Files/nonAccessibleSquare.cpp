#include <stdlib.h>
#include "nonAccessibleSquare.h"
#include "Square.h"
#include "Living.h"


nonAccessibleSquare::nonAccessibleSquare(int givenX, int givenY):Square(SQUARE_TYPE_NON_ACCESSIBLE, givenX, givenY)
{}

nonAccessibleSquare::~nonAccessibleSquare(){}

void nonAccessibleSquare::displayMenu(Hero** myHeroes)
{
    // This is a function that can't be called, since a Hero can never be in a Non Accessible Square,
    // so if this Function is called its a sign that something has gone wrong.

    cout << "ERROR: This is a non-Accessible Square\n";
    exit(1);
}

