#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include <iostream>

class Square : private Rectangle{



public:
    Square();
    Square(double dimension1);
    double calculateArea() const override;
};

#endif // RECT_H
