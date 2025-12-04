#ifndef LINE_H
#define LINE_H

#include "Point.h"  // Assuming Point class is defined in Point.h
#include <iostream>
#include "Shape.h"
// Forward declaration if needed (not required here since we include Point.h)
// class Point;

class Line : public Shape
{
    Point startPoint;
    Point endPoint;

public:
    Line();
    Line(int x1, int y1, int x2, int y2);

    void draw();
};

#endif // LINE_H
