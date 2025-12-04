#ifndef RECT_H
#define RECT_H

#include "Point.h"  // Assuming Point class is defined here
#include "Shape.h"
#include <iostream>

class Rect : public Shape{

    Point ul;  // upper left
    Point lr;  // lower right

public:
    Rect();
    Rect(int x1, int y1, int x2, int y2);

    void draw();
};

#endif // RECT_H
