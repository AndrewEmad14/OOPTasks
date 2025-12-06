#include "Point.h"


Point::Point() : x(0), y(0) {}


Point::Point(int m, int n) : x(m), y(n) {}

void Point::setX(int m)
{
    x = m;
}

void Point::setY(int n)
{
    y = n;
}


int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}
