#include "Circle.h"
#define PI 3.14
using namespace std;

// Default constructor
Circle::Circle() :GeoShape(0,0)
{

}

Circle::Circle(double dimension1) : GeoShape(dimension1, 0)
{
}

double Circle::calculateArea() const
{
   return dimension1 * dimension1 *PI;
}
