#include "Rectangle.h"
using namespace std;
Rectangle::Rectangle() : GeoShape(0,0){}

Rectangle::Rectangle(double dimension1,double dimension2) : GeoShape(dimension1,dimension2){}

double Rectangle:: calculateArea() const{

    return dimension1 * dimension2;

}
