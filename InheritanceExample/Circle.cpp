#include "Circle.h"

Circle::Circle()
{
    radius = 0;
}
Circle::Circle(int _x, int _y, int _radius) : Shape(_x, _y)
{
    radius = _radius;
}
/*
// Another valid option is:
Circle::Circle(int _x, int _y, int _radius)
{
Shape(_x, _y);
radius = _radius;
}
*/
int Circle::getRadius()
{
    return radius;
}

string Circle::draw()
{
    string msg = "I'm a Circle";
    return msg;
}