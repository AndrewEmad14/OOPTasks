#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeoShape.h"
#include <iostream>
class Rectangle : public GeoShape {
public:
    Rectangle();
    Rectangle(double width, double height);
    virtual double calculateArea() const override;

};

#endif // RECT_H
