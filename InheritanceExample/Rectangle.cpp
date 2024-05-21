#include "Rectangle.h"

Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

Rectangle::Rectangle(int _x, int _y, int _width, int _height) : Shape(_x, _y)
{
    width = _width;
    height = _height;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight()
{
    return height;
}

string Rectangle::draw()
{
    string msg = "I'm a Rectangle";
    return msg;
}