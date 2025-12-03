#include "Picture.h"

// Default constructor
Picture::Picture()
    : circleNum(0), rectangleNum(0), lineNum(0),
      pCircles(nullptr), pRects(nullptr), pLines(nullptr)
{
        circleNum=0;
        rectangleNum=0;
        lineNum=0;
        pCircles = NULL;
        pRects = NULL;
        pLines = NULL;
}

// Parameterized constructor
Picture::Picture(int circleNum, int rectangleNum, int lineNum, Circle *pCircles, Rect *pRects, Line *pLines)
    : circleNum(circleNum), rectangleNum(rectangleNum), lineNum(lineNum),
      pCircles(pCircles), pRects(pRects), pLines(pLines)
{
        this->circleNum = circleNum;
        this->rectangleNum = rectangleNum;
        this->lineNum = lineNum;
        this->pCircles = pCircles;
        this->pRects = pRects;
        this->pLines= pLines;
}
void Picture::setLines(int lineNum, Line *pLines)
{
    this->lineNum = lineNum;
    this->pLines = pLines;
}
void Picture::setCircles(int circleNum, Circle *pCircles)
{
    this->circleNum = circleNum;
    this->pCircles = pCircles;
}

// Set rectangles
void Picture::setRects(int rectangleNum, Rect *pRects)
{
    this->rectangleNum = rectangleNum;
    this->pRects = pRects;
}

void Picture::paint()
{
    int i;
    for(i=0; i<circleNum ; i++)
    {
        pCircles[i].draw();
    }

    for(i=0 ; i<rectangleNum ; i++)
    {
        pRects[i].draw();
    }

    for(i=0 ; i<lineNum; i++)
    {
        pLines[i].draw();
    }
}
Picture::~Picture(){
    delete[] pCircles;
    delete[] pRects;
    delete[] pLines;
}
