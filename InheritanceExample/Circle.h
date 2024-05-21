#ifndef CIRCLE
#define CIRCLE
#include "Shape.h"

class Circle : public Shape
{
    private:
        int radius;
    public:
        Circle();
        Circle(int _x, int _y, int _radius);
        int getRadius();
        string draw();
};
#endif