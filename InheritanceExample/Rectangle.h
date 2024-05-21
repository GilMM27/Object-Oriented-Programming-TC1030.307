#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
    private:
        int width;
        int height;
    public:
        Rectangle();
        Rectangle(int _x, int _y, int _width, int _height);
        int getWidth();
        int getHeight();
        string draw();
};

#endif