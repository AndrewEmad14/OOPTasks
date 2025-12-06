#ifndef POINT_H
#define POINT_H

class Point
{
    int x;
    int y;

public:
    Point();
    Point(int m, int n);

    void setX(int m);
    void setY(int n);

    int getX() const;
    int getY() const;
};

#endif // POINT_H
