#include "Circle.h"
#include <iostream>
using namespace std;

// Default constructor
Circle::Circle() : center()
{
    radius = 0;

}

Circle::Circle(int m, int n, int r) : center(m, n)
{
    radius = r;

}

void Circle::draw()
{
    cout<<"circle"<<endl;
}
