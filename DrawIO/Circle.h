#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"  // Assuming Point class is defined here
#include <iostream>
#include "Shape.h"
class Circle : public Shape
{
private:
    Point center;
    int radius;

public:
    Circle();
    Circle(int m, int n, int r);
    void draw();
};

#endif // CIRCLE_H
