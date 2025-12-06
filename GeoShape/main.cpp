#include <iostream>
#include "GeoShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

int main() {
    Rectangle rect(6,8);
    Circle circ(7);
    Triangle tri(8, 6);
    Square sq(4);
    cout << "Rectangle Area: " << rect.calculateArea() << endl;
    cout << "Circle Area: " << circ.calculateArea() << endl;
    cout << "Triangle Area: " << tri.calculateArea() << endl;
    cout << "Square Area: " << sq.calculateArea() << endl;
    return 0;
}
