#include "Square.h"

Square::Square(){}

Square::Square(int squaretype, int givenX, int givenY): squareType(squaretype), x(givenX), y(givenY)
{}

Square::~Square(){}
/* Getter for the x position of the square */
int Square::getX() const { return x; }

/* Setter for the x position of the square */
void Square::setX(int givenX) { this->x = givenX; }

/* Getter for the y position of the square */
int Square::getY() const { return y; }

/* Setter for the y position of the square */
void Square::setY(int givenY) { this->y = givenY; }

/* Getter for the Square Type */
int Square::getSquareType() const { return squareType; }
