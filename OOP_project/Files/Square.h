#ifndef SQUARE_H
#define SQUARE_H

const int SQUARE_TYPE_MARKET = 1;
const int SQUARE_TYPE_NON_ACCESSIBLE = 2;
const int SQUARE_TYPE_COMMON = 3;
//const int START_VALUE = -1;


class Square
{
    public:
        Square();
        Square(int, int, int);
        ~Square();
        int getX() const;
        void setX(int givenX);
        int getY() const;
        void setY(int givenY);
        int getSquareType() const;
    private:
        int squareType;
        int x;
        int y;
};

#endif // SQUARE_H
