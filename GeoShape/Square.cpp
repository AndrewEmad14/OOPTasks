#include "Square.h"
Square::Square() : Rectangle(0,0)
{
}

Square::Square(double dimension1) : Rectangle(dimension1,0)
{
}

double Square::calculateArea() const{

    return dimension1*dimension1;
}

