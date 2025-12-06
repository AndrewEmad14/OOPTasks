#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "GeoShape.h"
#include <iostream>

class Triangle : public GeoShape{



public:
    Triangle();
    Triangle(double dimension1,double dimension2);
    double calculateArea() const override;
};

#endif
