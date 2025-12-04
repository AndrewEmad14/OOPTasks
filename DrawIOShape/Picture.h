#ifndef PICTURE_H
#define PICTURE_H

#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

class Picture
{
private:
    int circleNum;
    int rectangleNum;
    int lineNum;

    Circle *pCircles;
    Rect *pRects;
    Line *pLines;

public:
    Picture();
    Picture(int circleNum, int rectangleNum, int lineNum, Circle *pCircles, Rect *pRects, Line *pLines);
    void setCircles(int circleNum, Circle *pCircles);
    void setRects(int rectangleNum, Rect *pRects);
    void setLines(int lineNum, Line *pLines);
    void paint();
    ~Picture();
};

#endif // PICTURE_H
