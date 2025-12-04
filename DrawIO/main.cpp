#include <iostream>
#include "Picture.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Shape.h"
#define NUMBER_OF_SHAPES 3
using namespace std;

//simple main()
int main()
{
    Picture myPic;

    Shape* shapes[NUMBER_OF_SHAPES]={new Circle(10, 20, 5),new Rect(0, 0, 100, 50),new Line(5, 5, 50, 50)};

    myPic.paint(shapes,NUMBER_OF_SHAPES);

    return 0;
}
