#ifndef CIRCLE_H
#define CIRCLE_H


#include <iostream>
#include "GeoShape.h"
class Circle : private GeoShape
{

public:
    Circle();
    Circle(double radius);
    double calculateArea()const override;
};

#endif // CIRCLE_H
