#include "Triangle.h"
Triangle::Triangle():GeoShape(0,0){}
Triangle::Triangle(double dimension1,double dimension2):GeoShape(dimension1,dimension2){}
double Triangle::calculateArea() const {

        return 0.5*dimension1*dimension2;

}
