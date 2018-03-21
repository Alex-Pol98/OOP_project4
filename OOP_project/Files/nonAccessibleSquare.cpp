#include <stdlib.h>
#include "nonAccessibleSquare.h"
#include "Square.h"
#include "Living.h"

/* Ctor of the class */
nonAccessibleSquare::nonAccessibleSquare(int givenX, int givenY):Square(SQUARE_TYPE_NON_ACCESSIBLE, givenX, givenY)
{}

/* Dtor of the class */
nonAccessibleSquare::~nonAccessibleSquare(){}

/* Function to displayMenu of a NonAccessible Square - works as an Error Checker */
void nonAccessibleSquare::displayMenu(Hero** myHeroes)
{
    // This is a function that can't be called, since a Hero can never be in a Non Accessible Square,
    // so if this Function is called its a sign that something has gone wrong.

    cout << "ERROR: This is a non-Accessible Square\n";
    exit(1);
}

