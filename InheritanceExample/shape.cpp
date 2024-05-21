#include "Shape.h"
Shape::Shape()
{
    x = 0;
    y = 0;
}
Shape::Shape(int _x, int _y)
{
    x = _x;
    y = _y;
}
string Shape::draw()
{
    string msg = "I'm a shape";
    return msg;
}
int Shape::getX()
{
    return x;
}
int Shape::getY()
{
    return y;
}
