#include "Rectangle.h"
#include <iostream>
using namespace std;
Rect::Rect() : ul(), lr()
{
}

Rect::Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2)
{
}

void Rect::draw()
{
    cout<<"rectangle"<<endl;
}
