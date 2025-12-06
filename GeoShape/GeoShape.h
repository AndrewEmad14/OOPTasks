#ifndef GEO_SHAPE_H
#define GEO_SHAPE_H

class GeoShape
{
    protected:
        double dimension1;
        double dimension2;
    public:
        GeoShape();
        GeoShape(double d1, double d2);
        virtual ~GeoShape() = default;
        virtual double calculateArea()const=0;
};

#endif // Shape

