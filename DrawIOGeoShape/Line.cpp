#include "Line.h"
#include <iostream>
using namespace std;

Line::Line() : startPoint(), endPoint(){
}

Line::Line(int x1, int y1, int x2, int y2) : startPoint(x1, y1), endPoint(x2, y2){
}

void Line::draw()
{
    cout<<"Line"<<endl;
}
