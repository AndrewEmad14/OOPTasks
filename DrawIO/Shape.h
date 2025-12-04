#ifndef SHAPE_H
#define SHAPE_H

class Shape
{

public:
    virtual ~Shape() = default;
    virtual void draw()=0;
};

#endif // Shape
