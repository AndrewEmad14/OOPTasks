#include "Picture.h"




void Picture::paint(Shape* myShape[],int shapeSize)
{

    for(int i=0;i<shapeSize;i++)
    {
        (*myShape)->draw();
        myShape++;
    }

}

